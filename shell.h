#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

/* macro definition */
#define BUFSIZE 1024
#define PRINTER(ch) (write(STDOUT_FILENO, ch, strlen(ch)))

/* Start command reading */
void prompt(void);
char *get_line();

/* file handling */
void file_reader(char *fl, char **argv);

#endif /* SHELL_H */
