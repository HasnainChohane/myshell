#include "tokenizer.h"
#include <cctype>

using namespace std;

vector<string> tokenize(const string& input) {
    vector<string> tokens;
    string token;

    for (char c : input) {
        if (isspace(c)) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        } 
        else if (c == '|' || c == '>') {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
            tokens.push_back(string(1, c));
        } 
        else {
            token += c;
        }
    }

    if (!token.empty()) tokens.push_back(token);

    return tokens;
}