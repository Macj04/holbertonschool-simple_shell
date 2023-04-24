#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

/**Libraries*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>

/**Prototypes*/
int check_space(char *line_buf);
void get_token(char *line_buf, char **array, char *delimit);
char *verify_path(char *line_buf, char **array_path);
int subprocess(char **argv);
void free_array_dir(char **array_dir);
int verify_status(char *filename);
int verify_dir(char *str);
char *func_getenv(const char *name);
extern char **environ;
int aux_subprocess(char **argv, char *path);

#endif
