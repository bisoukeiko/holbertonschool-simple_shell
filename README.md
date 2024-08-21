
![alt text](https://github.com/bisoukeiko/holbertonschool-simple_shell/blob/main/the%20gates%20of%20shell.jpeg?raw=true)

# Description

The Simple Shell project involves creating a minimalistic yet functional shell terminal emulation using the C programming language. This shell executes basic commands, interacts with the operating system, and introduces fundamental concepts of process management and input/output operations. We need to understand the functioning of a shell, system calls, and memory management.


## Table of Contents

Requirements

List of allowed functions and system calls+

Installation

Usage

Functions

Test function interactive mode

But also in non-interactive mode

Flowchart

Man page

Authors


## Requirements

- Working environment `Ubuntu 20.04 using GCC options -Wall -Werror -Wextra -pedantic -std=gnu89`
- Checker `Betty`
- Header file `Simple_Shell.h`
- Allowed editors `vi, vim, emacs`
- Compiler `GCC`
- All your files should `end with a new line`
- Your shell should `not have any memory leaks`
- No more than `5 functions per file`
- All your header files should `be include guarded`
- Use system calls only when you need to `(why?)`
## List of allowed functions and system calls+

* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* _exit (man 2 _exit)
* fflush (man 3 fflush)
* fork (man 2 fork)
* free (man 3 free)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* getpid (man 2 getpid)
* isatty (man 3 isatty)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* read (man 2 read)
* readdir (man 3 readdir)
* signal (man 2 signal)
* stat (__xstat) (man 2 stat)
* lstat (__lxstat) (man 2 lstat)
* fstat (__fxstat) (man 2 fstat)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
* wait4 (man 2 wait4)
* write (man 2 write)
## Installation
Clone the repository:
 
```git clone https://github.com/bisoukeiko/holbertonschool-simple_shell.git```

Navigate to the project directory:

```cd simple_shell```

## Usage

Compile the code using `gcc`:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

Run the executable:
```bash
./hsh
```
## Functions

#### We use functions like :

`shell.h` - Header file.

`count_tokens` - Count the number of tokens.

`tokenize_command` - Tokenize a command line and store each token in the array.

`get_command` - Tokenize a command line and store each token in the array.

`get_input` - Read one line from standard input and return a pointer to it.

`execute` - Spawn a child process to execute the specified command.

`free_path_dir` - Free an array of path directories.

`get_fullpath` - Searche for the full path of a command.

`process_command` - Check the full path of the command and run it if it is executable.

`main` - Display a prompt and wait for the user to type a command.

`execute` - Spawn a child process to execute the specified command.

`count_path` - Count the number of directories in PATH.

`allocate_path` - Reserve memory to store the directory paths in the PATH environment variable.

`store_path` - Store PATH directories in an array.

`tokenize_path` - Tokenize directories from the PATH.


## Test function interactive mode

- Your shell should work like this in interactive mode:
- $ ./hsh
- ($) /bin/ls
- hsh main.c shell.c
- ($)
- ($) exit
- $
#### example:
````
$ echo "/bin/ls" | ./hsh
"/bin/ls" | ./hsh
````
## But also in non-interactive mode

- $ echo "/bin/ls" | ./hsh
- hsh main.c shell.c test_ls_2
- $
- $ cat test_ls_2
- /bin/ls
- /bin/ls
- $
- $ cat test_ls_2 | ./hsh
- hsh main.c shell.c test_ls_2
- hsh main.c shell.c test_ls_2
- $

#### example:
````
~/holbertonschool-simple_shell$ echo "/bin/ls"  | ./hsh
AUTHORS     command.c   get_fullpath.c  process_command.c   simple_shell.c  README.md
execute.c   hsh     shell.h     tokenize_path.c
``````
## Flowchart

![alt text](https://github.com/bisoukeiko/holbertonschool-simple_shell/blob/main/Flowchart.png?raw=true)
## Man page

You can check the [Man Page](https://github.com/bisoukeiko/holbertonschool-simple_shell/blob/main/man_1_simple_shell) of the function here and more example.
## Authors

If you have any questions ask:

- [@Bisoukeiko](https://www.github.com/bisoukeiko)
- [@Guillaume.farina](https://www.github.com/guillaumefarina)