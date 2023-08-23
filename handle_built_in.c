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
 * builtin_handling - handle builtin commands.
 *
 * @line: tokenized read input
 * @err: state after execution
 * Return: -1 -> fail,
 *		0 -> otherwise
 */
int builtin_handling(char **line, int err)
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
			return ((builtins + i)->fun(line, err));
		}
		i++;
	}
	return (-1);
}