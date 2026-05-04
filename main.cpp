#include <iostream>
#include <string>
#include <vector>
#include <sstream>

void execute(std::vector<std::string>& args); // from executor.cpp

std::vector<std::string> split(const std::string& str, char delimiter = ' ') {
    std::stringstream ss(str);
    std::string word;
    std::vector<std::string> words;
    while (std::getline(ss, word, delimiter)) {
        if (!word.empty()) words.push_back(word);
    }
    return words;
}

int main() {
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;
    std::string input;

    while (true) {
        std::cout << "$ ";
        if (!std::getline(std::cin, input)) break;
        if (input.empty()) continue;
        
        std::vector<std::string> args = split(input, ' ');
        execute(args);
    }
    return 0;
}