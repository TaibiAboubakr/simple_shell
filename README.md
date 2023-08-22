#  *Simple Shell*

This is a basic UNIX command interpreter project implemented in C as part of the ALX Software Engineering program.
The project focuses on building a simple shell that allows users to execute various commands and explore basic shell
functionalities

## *Introduction*

The Simple Shell project is a collaborative effort aimed at providing an understanding of how a shell works, along with C programming concepts

## *Getting Started*

To use the Simple Shell, follow these steps:

1. Clone the repository: `git clone https://github.com/aboubakr-taibi.git`
2. Compile the source code: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
3. Run the shell: `./hsh`
4. Input commands at the prompt and observe the output


## *Built-in Commands*

    exit: Used to exit the shell. Usage: exit [status]
    env: Prints current environment variables. Usage: env
    cd: Changes the current working directory. Usage: cd [DIRECTORY]
    $$: Expands to the shell's process ID (PID)
    $?: Expands to the exit status of the last command
    Comments (#): Text after '#' is ignored as a comment

## *Supported System Calls :*

 * *File Manipulation:* access, close, execve, open, read, write
 * *Process Control:* fork, exit, _exit, getpid, isatty, kill, wait, waitpid, wait3, wait4
 * *Directory Manipulation:* chdir, closedir, opendir, readdir
 * *Memory Allocation:* free, malloc
 * *Input/Output:* getline
 * *String Manipulation:* strtok
 * *Error Reporting:* perror
 * *Signal Handling:* signal
 * *File Information:* stat, lstat, fstat 

## *Contributors*

    Imane Zenasni
    Aboubakr Taibi
