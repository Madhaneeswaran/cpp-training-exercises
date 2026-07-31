#include <iostream>
#include <string>

int main() {
    std::cout << "--- cout: standard output, BUFFERED ---\n";
    std::cout << "this goes to normal program output\n";

    std::cout << "\n--- cerr: standard error, UNBUFFERED ---\n";
    std::cerr << "this goes to the error stream instead\n";
    std::cout << "(run this program as: ./10_io_streams.exe 2> errors.txt\n"
              << " and only the cerr line ends up in errors.txt -- cout and cerr\n"
              << " are genuinely SEPARATE streams, not just different colors.)\n";

    std::cout << "\n--- why the buffered/unbuffered difference matters ---\n";
    std::cout << "cout batches output and writes it out in chunks (for speed) --\n"
              << "if your program crashes before a flush, buffered cout output can be\n"
              << "LOST. cerr writes IMMEDIATELY, every time -- slower, but you'll always\n"
              << "see the error message even if the program crashes right after.\n";
    std::cout << "(That's WHY error/diagnostic messages traditionally go to cerr, not cout.)\n";

    std::cout << "\n--- cin: reading input ---\n";
    std::cout << "type your name and press Enter: ";
    std::string name;
    std::cin >> name;   // reads ONE whitespace-separated token
    std::cout << "hello, " << name << "!\n";

    std::cout << "\n--- cin >> stops at whitespace -- try a name with a space ---\n";
    std::cout << "type your full name (first last) and press Enter: ";
    std::string first, last;
    std::cin >> first >> last;   // TWO reads, one per word
    std::cout << "first = \"" << first << "\", last = \"" << last << "\"\n";
    std::cout << "<-- PREDICT: if you type just one word, what happens to `last`?\n"
              << "(it will sit there waiting for another token -- try it, then Ctrl+C)\n";

    std::cout << "\n--- reading a WHOLE line (including spaces) needs getline ---\n";
    std::cin.ignore();   // clear the leftover '\n' still sitting in the input buffer
    std::cout << "type a full sentence: ";
    std::string sentence;
    std::getline(std::cin, sentence);
    std::cout << "you said: \"" << sentence << "\"\n";

    return 0;
}

/*
   TRY IT NON-INTERACTIVELY (feeds input via a pipe, so you don't have to
   type each time):
     echo "Ada Lovelace
     Hello there, this is a whole sentence" | ./10_io_streams.exe

   JS BRIDGE: cout/cerr map roughly to console.log vs console.error -- Node
   also treats stdout and stderr as separate streams you can redirect
   independently, so `2> errors.txt` will feel familiar if you've ever done
   `node app.js 2> errors.txt`.
*/
