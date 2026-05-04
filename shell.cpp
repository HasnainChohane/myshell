#include "tokenizer.h"
#include <cctype>

using namespace std;

vector<string> tokenize(const string& input) {
    vector<string> tokens;
    string token;
    bool in_quotes = false;

    for (size_t i = 0; i < input.size(); i++) {
        char c = input[i];

        // Handle quotes
        if (c == '"') {
            in_quotes = !in_quotes;
            continue;
        }

        // If space and not inside quotes → split
        if (isspace(c) && !in_quotes) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        }

        // Handle operators when NOT inside quotes
        else if (!in_quotes && (c == '|' || c == '<' || c == '>')) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }

            // Handle >> (append)
            if (c == '>' && i + 1 < input.size() && input[i + 1] == '>') {
                tokens.push_back(">>");
                i++;
            } else {
                tokens.push_back(string(1, c));
            }
        }

        else {
            token += c;
        }
    }

    if (!token.empty())
        tokens.push_back(token);

    return tokens;
}