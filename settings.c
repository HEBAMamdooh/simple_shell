#include "shell.h"

/**
 * _atoi - converts a string to an integer.
 *
 * @s : the converted string.
 *
 * Return: integer.
 *
*/
int _atoi(char *s)
{
	int n, num, sign;

	num = 0;
	sign = 1;

	for (n = 0; s[n] != '\0' && !(s[n] >= '0' && s[n] <= '9'); n++)
	{
		if (s[n] == '-')
			sign = sign * -1;
	}

	for (n = 0; s[n] != 0; n++)
	{
		if (s[n] >= '0' && s[n] <= '9')
			num = num * 10 + sign * (s[n] - '0');
		if (num != 0 && !(s[n] >= '0' && s[n] <= '9'))
			return (num);
	}
	return (num);
}

/**
 * print_number - prints an unsigned int.
 *
 * @n: the integer.
 *
 * Return: nothing.
 */
void print_number(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
		print_number(x / 10);
	putchar(x % 10 + '0');
}

/**
 * print_number_in - print integer.
 *
 * @n: the integer.
 *
 * Return: nothing.
 */
void print_number_in(int n)
{
	unsigned int t = n;

	if (n < 0)
	{
		putchar('-');
		t = -t;
	}
	if ((t / 10) > 0)
		print_number(t / 10);
	putchar(t % 10 + '0');
}

/**
 * execute - executes the read command.
 *
 * @t_argv: tokenized read line
 * @line: vanilla input line
 * @c: exit arg
 * @argv: program name.
 *
 * Return: 1 -> command value NULL,
 *		-1 -> false,
 *		0 -> execute.
 */
int execute(char **t_argv, char *line, int c, char **argv)
{
	int status;
	pid_t child_pid;

	if (*t_argv == NULL)
		return (-1);
	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (child_pid == 0)
	{
		if (str_cmp(*t_argv, "./", 2) != 0 && str_cmp(*t_argv, "/", 1) != 0)
			get_path(t_argv);
		if (execve(*t_argv, t_argv, environ) == -1)
		{
			display_error(t_argv[0], c, argv);
			free(line);
			free(t_argv);
			exit(2);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
