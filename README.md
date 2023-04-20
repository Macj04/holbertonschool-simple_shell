![](https://static.wixstatic.com/media/aaf0fb_44565f883075417ab38af433fbc0334b~mv2.png/v1/fill/w_320,h_320,al_c,q_85,usm_0.66_1.00_0.01,enc_auto/aaf0fb_44565f883075417ab38af433fbc0334b~mv2.png)

***
# C - Simple Shell
***

## What is a Shell
***
The shell it's a interpreter or rather an executable file that must interpret the commands, transmit them to the system and return the result. Its function is to read the command line, interpret its meaning, carry out the command and then return the result via the outputs.

***
## Our Simple Shell
***
Through the following project we have created our own interpreter of commands Linux capable of providing a user interface that can either invoke or execute available commands. For said project we have used some of the functions basic of language C, such that we can develop a fully readable.

***
## Requirements
> A list of requirements used within the project:
***

* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to (why?)

***
## List of allowed functions and system calls
***

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
* printf (man 3 printf)
* fprintf (man 3 fprintf)
* vfprintf (man 3 vfprintf)
* sprintf (man 3 sprintf)
* putchar (man 3 putchar)
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

***
## Compilation
> Your shell will be compiled this way:
***
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

***
## Syntax of Shell
***
#cisfun$ [command] -[parameters]

***
## Example of Use
***

***
## Authors
[Lautaro Rodriguez](https://github.com/LautareteX)
[Miguel Coa](https://github.com/Macj04)

