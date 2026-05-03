#pragma once
#include <vector>
#include <string>

struct Command {
    std::vector<std::string> args;
    std::string output_file;
};

std::vector<Command> parse(const std::vector<std::string>& tokens);