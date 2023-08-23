#include "shell.h"

/**
 * _cd - change the directory when using cd command.
 *
 * @t_argv: tokenized read input.
 * @error: state error.
 *
 * Return: 0 -> success,
 *		1 -> fail.
 */
int _cd(char **t_argv, __attribute__((unused))int error)
{
	int value = -1;
	char currentDir[PATH_MAX];

	if (t_argv[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_strcmp(t_argv[1], "-") == 0)
		value = chdir(getenv("OLDPWD"));
	else
		value = chdir(t_argv[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(currentDir, sizeof(currentDir));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", currentDir, 1);
	}
	return (0);
}

/**
 * display_env - display the env var.
 *
 * @t_argv: tokenized read input
 * @error: state of execution
 *
 * Return: 0
 */
int display_env(__attribute__((unused)) char **t_argv,
		__attribute__((unused)) int error)
{
	size_t i;
	int sz;

	for (i = 0; environ[i] != NULL; i++)
	{
		sz = strlen(environ[i]);
		write(1, environ[i], sz);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * exit_sh - handle exit commands in the shell.
 *
 * @t_argv: tokenized read line.
 * @line: read line with no alterations.
 * @argv: shell program name.
 * @c: counter.
 *
 * Return: Nothing.
 */
void exit_sh(char **t_argv, char *line, char **argv, int c)
{
	int stat, i = 0;

	if (t_argv[1] == NULL)
	{
		free(line);
		free(t_argv);
		exit(EXIT_SUCCESS);
	}

	while (t_argv[1][i])
	{
		if (_isalpha(t_argv[1][i++]) != 0)
		{
			custom_error(argv, c, t_argv);
			break;
		}
		else
		{
			stat = _atoi(t_argv[1]);
			free(line);
			free(t_argv);
			exit(stat);
		}
	}
}

/**
 * _echo - handle all echo related command.
 *
 * @error: state of execution.
 * @t_argv: tokenized read line.
 *
 * Return: 0
 */
int _echo(char **t_argv, int error)
{
	char *path;
	unsigned int pid = getppid();

	if (str_cmp(t_argv[1], "$?", 2) == 0)
	{
		print_number_in(error);
		PRINTER("\n");
	}
	else if (str_cmp(t_argv[1], "$$", 2) == 0)
	{
		print_number(pid);
		PRINTER("\n");
	}
	else if (str_cmp(t_argv[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINTER(path);
		PRINTER("\n");
		free(path);
	}
	else
		return (print_echo(t_argv));
	return (1);
}

/**
 * print_echo - executes common echo uses.
 *
 * @t_argv: tokenized read input.
 *
 * Return: 0 -> success,
 *		-1 -> fail.
 */
int print_echo(char **t_argv)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve("/bin/echo", t_argv, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
	{
		return (-1);
	}
	else
	{
		do
		{
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
