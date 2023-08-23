#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

/* macro definition */
#define BUFSIZE 1024
#define PRINTER(ch) (write(STDOUT_FILENO, ch, strlen(ch)))

/**
 * builtin struct - struct that helps to handle built in commands.
 *
 * @blt_cmd: command name.
 * @fun: function to execute that matches the command.
 */
typedef struct built
{
	char *blt_cmd;
	int (*fun)(char **line, int err);
} builtin;

/* Command reading */
void prompt(void);
void handle_signal(int n);
void comment_handle(char *line);
char *get_line();

/* Memory Check */
void *re_alloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* file handling */
void file_handling(char *line, int i, FILE *fd, char **argv);
void file_reader(char *fl, char **argv);

unsigned int mirror(char c, const char *s);
char *str_tok(char *s, const char *delim);
char **tokenizer(char *line);

#endif /* SHELL_H */
