# myshell
MyShell is a custom command-line shell developed in C++ that simulates the behavior of a Unix-like shell. It is designed to understand operating system concepts such as process creation, command parsing, and inter-process communication.
# MyShell – Custom C++ Unix-like Shell

MyShell is a custom command-line shell implemented in C++. It replicates core features of a Unix-like shell and demonstrates key operating system concepts such as process management, command parsing, and inter-process communication.

---

## Features

- Execution of system commands using fork() and execvp()
- Support for piping between commands using |
- Input and output redirection using <, >, >>
- Built-in commands:
  - cd: change directory
  - pwd: print working directory
  - exit: exit the shell
- Tokenizer and parser for command processing
- Modular and scalable architecture

---

## Concepts Used

This project is built to strengthen understanding of:

- Process creation using fork()
- Program execution using execvp()
- Process synchronization using wait()
- File descriptor manipulation using dup2()
- Command parsing and tokenization
- Operating system shell design principles

---

## Project Structure

myshell/
│
├── src/
│   ├── main.cpp
│   ├── shell.cpp
│   ├── tokenizer.cpp
│   ├── parser.cpp
│   ├── executor.cpp
│   └── builtins.cpp
│


├── include/
│   ├── shell.h
│   ├── tokenizer.h
│   ├── parser.h
│   ├── executor.h
│   └── builtins.h
│
├── Makefile
└── README.md

---

## How to Build and Run

### Compile the project
make

### Run the shell
./myshell

---

## Example Usage

MyShell> ls
MyShell> pwd
MyShell> cd ..
MyShell> ls | grep cpp
MyShell> echo hello > file.txt
MyShell> cat < file.txt
MyShell> exit

---

## Future Improvements

- Background process execution using &
- Command chaining using && and ||
- Environment variable support such as $HOME and $PATH
- Command history functionality
- Auto-completion support
- Script execution support

---

## Learning Outcome

This project provides hands-on experience with low-level system programming and helps in understanding how real shells like Bash operate internally. It strengthens knowledge in operating systems, process control, and C++ system programming.

---

## Author

Hasnain Chohan

---

## License

This project is created for educational purposes and is open for learning and modification.
