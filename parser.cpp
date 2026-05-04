#include "parser.h"

using namespace std;

vector<Command> parse(const vector<string>& tokens) {
    vector<Command> commands;
    Command current;

    for (size_t i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "|") {
            commands.push_back(current);
            current = Command();
        } 
        else if (tokens[i] == ">") {
            if (i + 1 < tokens.size()) {
                current.output_file = tokens[i + 1];
                i++;
            }
        } 
        else {
            current.args.push_back(tokens[i]);
        }
    }

    if (!current.args.empty())
        commands.push_back(current);

    return commands;
}