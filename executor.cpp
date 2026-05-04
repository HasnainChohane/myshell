#include "builtins.h"
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>

void execute(std::vector<std::string>& args) {
    if (args.empty()) return;
    
    // Handle builtins in parent process
    if (handle_builtin(args)) {
        return;
    }
    
    // External command
    std::string exec_path = find_in_path(args[0]);
    if (exec_path.empty()) {
        std::cout << args[0] << ": command not found" << std::endl;
        return;
    }
    
    pid_t pid = fork();
    if (pid == 0) {
        // Child
        std::vector<char*> c_args;
        for (auto& arg : args) c_args.push_back(&arg[0]);
        c_args.push_back(nullptr);
        
        execv(exec_path.c_str(), c_args.data());
        std::cerr << "Failed to execute " << args[0] << std::endl;
        exit(1);
    } 
    else if (pid > 0) {
        // Parent
        int status;
        waitpid(pid, &status, 0);
    } 
    else {
        std::cerr << "Fork failed" << std::endl;
    }
}