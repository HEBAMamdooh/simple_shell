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

extern char **environ;

/* macro definition */
#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
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
void handle_signal(int n);
void prompt(void);

/* built in handling */
int _cd(char **t_argv, __attribute__((unused))int error);
int display_env(__attribute__((unused)) char **t_argv,
		__attribute__((unused)) int error);
void exit_sh(char **t_argv, char *line, char **argv, int c);
int _echo(char **t_argv, int error);
int print_echo(char **t_argv);

/* environment */
void _setenv(char **new_env);
char *_getenv(char *env_n);

/* errors */
void custom_error(char **argv, int c, char **frscommand);
void display_err(char **argv, int c,char *frscommand);

/* file handling */
void file_handling(char *line, int i, FILE *fd, char **argv);
void file_reader(char *fl, char **argv);

/* lines */
void comment_handle(char *line);
char *get_line();

/* Memory Check */
void *re_alloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* settings */
int _strcmp(char *s1, char *s2);
int str_cmp(const char *s1, const char *s2, size_t n);
int _isalpha(int c);
int num_len(int num);
char *_itost(int num);
void array_rev(char *arr, int len);
char *str_cpy(char *dest, char *src);
char *str_cat(char *dest, char *src);
char *str_chr(char *s, char c);
char *str_dup(char *str);

/* settings */
int _atoi(char *s);
void print_number(unsigned int n);
void print_number_in(int n);

/* Tokens */
unsigned int mirror(char c, const char *s);
char *str_tok(char *s, const char *delim);
char **tokenizer(char *line);

#endif /* SHELL_H */
