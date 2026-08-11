#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>  // For std::transform
#include <cctype>     // For std::tolower

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
        std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
        ++wordCount[word];
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

