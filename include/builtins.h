#pragma once
#include <vector>
#include <string>

bool handle_builtin(const std::vector<std::string>& args);
std::string find_in_path(const std::string& command);