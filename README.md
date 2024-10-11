 # 🐚 Minishell (42 School Project)

## 🌟 Overview

**Minishell** is a simplified shell project developed as part of the 42 School curriculum. The aim of the project is to create a functional shell that mimics some of the core behaviors of popular shells like `bash`, while providing a solid foundation for learning about process management, input/output redirection, pipes, and system calls in UNIX-based systems.

The project focuses on replicating the basic functionalities of a shell without any bonus features, keeping the implementation minimal and adhering to specific requirements. The project encourages you to explore low-level system programming in C, making use of system calls such as `fork()`, `execve()`, `pipe()`, and signals handling.

## ✨ Features

The following functionalities are implemented:

1. **💻 Prompt display**:
    - A prompt is displayed where the user can enter commands.
   
2. **⚙️ Command execution**:
    - The shell can execute binary commands located in `$PATH`, similar to `/bin/ls` or `/usr/bin/cat`.

3. **🔧 Built-in commands**:
    - The shell implements a few essential built-in commands:
      - `echo` with the `-n` option.
      - `cd` for changing the current directory.
      - `pwd` to print the current working directory.
      - `export` to set environment variables.
      - `unset` to remove environment variables.
      - `env` to display the environment variables.
      - `exit` to terminate the shell.

4. **🌐 Environment variable handling**:
    - The shell manages environment variables and allows manipulation using built-in commands like `export` and `unset`.

5. **📄 Redirections**:
    - Supports input (`<`) and output (`>`, `>>`) redirections for commands.
   
6. **🔗 Pipes**:
    - Implements pipes (`|`), enabling command chaining by sending the output of one command to the input of another.

7. **🚨 Signal handling**:
    - Handles signals for `Ctrl+C`, `Ctrl+D`, and `Ctrl+\` to behave like a normal shell:
      - `Ctrl+C`: Sends an interrupt signal, should not terminate the shell.
      - `Ctrl+D`: Closes the shell when the input is empty.
      - `Ctrl+\`: Should do nothing.

8. **❗ Error handling**:
    - Proper error messages are displayed for invalid commands, file access issues, or command execution problems.

## 🚫 Not Implemented (No Bonus Features)

The following bonus functionalities are not included in this version:
- Logical operators (`&&`, `||`).

## 📋 Requirements

- **Language**: C (with allowed standard libraries such as `unistd.h`, `fcntl.h`, `stdio.h`, `signal.h`, etc.)
- **Operating System**: Linux-based (preferably tested on macOS or Linux).
- **Compiler**: `cc` with the following flags:
  - `-Wall -Wextra -Werror`
  
## Installation 📦

To compile and test **Minishell**, follow these steps:

1. Clone the repository:
   ```bash
   git clone git@github.com:AnnLvu/minishell_42.git
   cd minishell_42

## 🚀 Usage

 ```bash
 make        # Compiles the minishell library ⚒️
 ./minishell # Run the shell 
 make clean  # Cleans up object files 🧹
 make fclean  # Full cleanup of generated files 🧼
 make re     # Rebuild everything from scratch 🔄
```

### 📄 Example Commands

```bash
# Running a command in $PATH
ls -l

# Redirection
cat < input.txt > output.txt

# Piping
ls | grep minishell

# Built-ins
pwd
export VAR=value
echo $VAR
unset VAR
env
exit
```

## 🎯 Conclusion

This project provides a basic yet functional shell that introduces you to the inner workings of a command-line interface, process control, and system-level programming. Through the implementation of minishell, you'll gain a deep understanding of how shells work at the fundamental level, focusing on essential UNIX system calls and process management.

