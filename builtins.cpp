#include "builtins.h"
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <limits.h>
#include <filesystem>

std::string find_in_path(const std::string& command) {
    const char* path_env = std::getenv("PATH");
    if (!path_env) return "";
    
    std::string path_var = path_env;
    size_t start = 0;
    size_t end = path_var.find(':');
    
    while (end!= std::string::npos) {
        std::string dir = path_var.substr(start, end - start);
        std::filesystem::path file_path = std::filesystem::path(dir) / command;
        
        if (std::filesystem::exists(file_path) && 
          !std::filesystem::is_directory(file_path) &&
            access(file_path.c_str(), X_OK) == 0) {
            return file_path.string();
        }
        start = end + 1;
        end = path_var.find(':', start);
    }
    
    // Check last dir
    std::string dir = path_var.substr(start);
    std::filesystem::path file_path = std::filesystem::path(dir) / command;
    if (std::filesystem::exists(file_path) && 
      !std::filesystem::is_directory(file_path) &&
        access(file_path.c_str(), X_OK) == 0) {
        return file_path.string();
    }
    
    return "";
}

bool handle_builtin(const std::vector<std::string>& args) {
    if (args.empty()) return false;
    const std::string& cmd = args[0];

    if (cmd == "exit") {
        exit(0);
    }
    else if (cmd == "echo") {
        for (size_t i = 1; i < args.size(); ++i) {
            std::cout << args[i];
            if (i < args.size() - 1) std::cout << " ";
        }
        std::cout << std::endl;
        return true;
    }
    else if (cmd == "type") {
        if (args.size() < 2) return true;
        std::string cmd_to_check = args[1];
        
        if (cmd_to_check == "echo" || cmd_to_check == "exit" || 
            cmd_to_check == "type" || cmd_to_check == "pwd" || cmd_to_check == "cd") {
            std::cout << cmd_to_check << " is a shell builtin" << std::endl;
        } else {
            std::string path = find_in_path(cmd_to_check);
            if (!path.empty()) {
                std::cout << cmd_to_check << " is " << path << std::endl;
            } else {
                std::cout << cmd_to_check << ": not found" << std::endl;
            }
        }
        return true;
    }
    else if (cmd == "pwd") {
        char cwd[PATH_MAX];
        if (getcwd(cwd, sizeof(cwd))!= nullptr) {
            std::cout << cwd << std::endl;
        } else {
            std::cerr << "pwd: error" << std::endl;
        }
        return true;
    }
    else if (cmd == "cd") {
        const char* path;
        if (args.size() == 1) {
            path = std::getenv("HOME");
            if (!path) {
                std::cerr << "cd: HOME not set" << std::endl;
                return true;
            }
        } else {
            path = args[1].c_str();
        }
        
        if (chdir(path)!= 0) {
            std::cerr << "cd: " << path << ": No such file or directory" << std::endl;
        }
        return true;
    }
    
    return false;
}