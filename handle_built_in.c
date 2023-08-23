#include "shell.h"

/**
 * check_builtin - Check builtin commands.
 *
 * @argv: Read input command.
 * Return: 0 -> success,
 *		-1 -> fail.
 */
int check_builtin(char **argv)
{
	int i = 0;
	builtin builtins[] = {
		{"cd", NULL},
		{"echo", NULL},
		{NULL, NULL}
	};

	if (*argv == NULL)
		return (-1);

	while ((builtins + i)->blt_cmd)
	{
		if (_strcmp(argv[0], (builtins + i)->blt_cmd) == 0)
			return (0);
		i++;
	}
	return (-1);
}

/**
 * handle_builtin - handle builtin commands.
 *
 * @line: tokenized read input.
 * @error: state after execution.
 *
 * Return: -1 -> fail,
 *		0 -> otherwise
 */
int handle_builtin(char **line, int error)
{
	int i = 0;
	builtin builtins[] = {
		{"cd", _cd},
		{"env", display_env},
		{"echo", _echo},
		{NULL, NULL}};

	while ((builtins + i)->blt_cmd)
	{
		if (_strcmp(line[0], (builtins + i)->blt_cmd) == 0)
		{
			return ((builtins + i)->fun(line, error));
		}
		i++;
	}
	return (-1);
}

/**
 * comment_handle - handling comments in the command.
 *
 * @line: The Checked line.
 * Return: Nothing.
 */
void comment_handle(char *line)
{
	int i;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == '#')
		{
			line[i] = '\0';
			break;
		}
	}
}
