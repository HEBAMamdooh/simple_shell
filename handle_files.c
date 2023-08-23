#include "shell.h"

/**
 * file_handling - tokenizes the read input from file.
 *
 * @line: Command from a file.
 * @i: Error counter.
 * @fd: File description
 * @argv: shell program name.
 *
 * Return: Nothing.
 */
void file_handling(char *line, int i, FILE *fd, char **argv)
{
	char **tokens;
	int ret = 0;

	tokens = tokenizer(line);

	if (str_cmp(tokens[0], "exit", 4) == 0)
	{
		exit_file(tokens, line, fd);
	}
	else if (check_builtin(tokens) == 0)
	{
		ret = handle_builtin(tokens, ret);
		free(tokens);
	}
	else
	{
		ret = execute(tokens, line, i, argv);
	}
}

/**
 * file_reader - read command from file.
 *
 * @fl: File name.
 * @argv: Shell program name.
 *
 * Return: 0 on exit.
 */
void file_reader(char *fl, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t sz = 0;
	int i = 0;

	if (access(fl, F_OK) == 0)
	{
		fp = fopen(fl, "r");
		if (fp == NULL)
			exit(EXIT_FAILURE);

		while ((getline(&line, &sz, fp)) != -1)
		{
			i++;
			file_handling(line, i, fp, argv);
		}
		if (line)
			free(line);
		fclose(fp);
		exit(0);
	}
	else
	{
		PRINTER(argv[0]);
		PRINTER(": ");
		PRINTER(fl);
		PRINTER(": No such file or directory\n");
	}
}

/**
 * exit_file - exits the file.
 *
 * @line: read line from a file.
 * @t_argv: tokenized read line from file.
 * @fd: file descriptor.
 *
 * Return: nothing
 */
void exit_file(char **t_argv, char *line, FILE *fd)
{
	int status, i = 0;

	if (t_argv[1] == NULL)
	{
		free(line);
		free(t_argv);
		fclose(fd);
		exit(errno);
	}
	while (t_argv[1][i])
	{
		if (_isalpha(t_argv[1][i++]) < 0)
			perror("illegal number");
	}
	status = _atoi(t_argv[1]);
	free(line);
	free(t_argv);
	fclose(fd);
	exit(status);
}
