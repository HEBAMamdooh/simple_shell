#include <stdio.h>
#include "shell.h"

/**
 * main - My shell entry point.
 *
 * @argc: number of arguments.
 * @argv: array of arguments.
 *
 * Return: User entry processing.
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *line, **av_token;
	int i = 0, entry = 1, st = 0;

	if (argv[1] != NULL)
		file_reader(argv[1], argv);

	if (signal(SIGINT, handle_signal) == SIG_ERR)
	{
		perror("couldn't catch signal");
		exit(EXIT_FAILURE);
	}

	while (entry)
	{
		i++;

		if (isatty(STDIN_FILENO))
			prompt();
		else
			write(STDERR_FILENO, "", 0);
		line = get_line();
		if (line[0] == '\0')
			continue;
		av_token = tokenizer(line);

		if (_strcmp(av_token[0], "exit") == 0)
			_exit_sh(av_token, line, argv, i);
		else if (check_builtin(av_token) == 0)
		{
			st = handle_builtin(av_token, st);
			free_buffers(av_token, line);
			continue;
		}
		else
			st = execute(av_token, line, i, argv);

		free_buffers(av_token, line);
	}
	return (entry);
}
