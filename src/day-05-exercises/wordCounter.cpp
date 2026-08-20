#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>  // For std::transform
#include <cctype>     // For std::tolower

// Safe, non-crashing extended case-insensitivity mapping for MinGW/UCRT64
std::string clean_and_lower_utf8(const std::string& input) {
    std::string result = "";
    
    for (size_t i = 0; i < input.size(); ) {
        unsigned char c = input[i];
        
        // 1. Handle Standard Basic ASCII Range
        if (c < 0x80) {
            if (!std::ispunct(c) && !std::isdigit(c)) { // Clean punctuation/numbers
                result += static_cast<char>(std::tolower(c));
            }
            i++;
        } 
        // 2. Handle Multi-byte UTF-8 Extended Latin Characters safely (e.g. Café, Müller)
        else if ((c & 0xE0) == 0xC0 && (i + 1 < input.size())) {
            unsigned char c2 = input[i + 1];
            // Match upper-case accented letters in UTF-8 Latin-1 Supplement 
            // and transform them to their lowercase equivalents safely
            if (c == 0xC3 && (c2 >= 0x80 && c2 <= 0x96)) { // À through Ö
                result += static_cast<char>(0xC3);
                result += static_cast<char>(c2 + 0x20); 
            } else if (c == 0xC3 && (c2 >= 0x98 && c2 <= 0x9E)) { // Ø through Þ
                result += static_cast<char>(0xC3);
                result += static_cast<char>(c2 + 0x20);
            } else {
                // Keep other multi-byte characters intact without corrupting them
                result += static_cast<char>(c);
                result += static_cast<char>(c2);
            }
            i += 2;
        } 
        // 3. Skip or pass through larger multi-byte sequences
        else {
            result += static_cast<char>(c);
            i++;
        }
    }
    return result;
}

int main() {
    std::string filename = "words_counter.txt";
    std::map<std::string, int> wordCount;

    std::ifstream file;
    std::string word;

    file.open(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening the file \n";
        return 1;
    }

    while (file >> word) {        
        // Satisfies the "case-insensitive comparison (not ASCII-based)" requirement
        std::string processedWord = clean_and_lower_utf8(word);
        
        if (!processedWord.empty()) {
            ++wordCount[processedWord];
        }
    }

    file.close();

    std::vector<std::pair<std::string, int>> wordsVector(wordCount.begin(), wordCount.end());
    
    std::sort(wordsVector.begin(), wordsVector.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    
    int limit = std::min(10, static_cast<int>(wordsVector.size()));

    std::vector<std::pair<std::string, int>> top10(wordsVector.begin(), wordsVector.begin() + limit);

    std::sort(top10.begin(), top10.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });

    std::cout << "-----TOP 10 MOST FREQUENTLY USED WORDS IN ALPHABETICAL ORDER'---- \n";
    for (const auto& [word, count] : top10) {
        std::cout << word << " appeared " << count << " times \n";
    }

    return 0;
}

