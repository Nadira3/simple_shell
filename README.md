## C - SIMPLE SHELL

#### Write a simple UNIX command interpreter.

##### General

```
Who designed and implemented the original Unix operating system
Who wrote the first version of the UNIX shell
Who invented the B programming language (the direct predecessor to the C programming language)
Who is Ken Thompson
How does a shell work
What is a pid and a ppid
How to manipulate the environment of the current process
What is the difference between a function and a system call
How to create processes
What are the three prototypes of main
How does the shell use the PATH to find the programs
How to execute another program with the execve system call
How to suspend the execution of a process until one of its children terminates
What is EOF / “end-of-file”?
```

#### Features
```
- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- Handle command lines with arguments
- Handle the PATH
- Implement the exit built-in, that exits the shell
- Implement the env built-in, that prints the current environment
- Write your own getline function
- You are not allowed to use strtok
- handle arguments for the built-in exit
- Implement the setenv and unsetenv builtin commands
- Implement the builtin command cd
- Handle the commands separator
- Handle the && and || shell logical operators
- Implement the alias builtin command
- Handle variables replacement
- Handle comments (#)
- Take a file as a command line argument
```
