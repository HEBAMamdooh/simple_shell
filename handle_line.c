#include "shell.h"

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

/**
 * get_line - read input commands from the STDIN stream.
 *
 * Return: input.
 */
char *get_line()
{
	int i, buffSZ = BUFSIZE, read_d;
	char c = 0, *line_ptr = malloc(buffSZ);

	if (line_ptr == NULL)
	{
		free(line_ptr);
		return (NULL);
	}

	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		read_d = read(STDIN_FILENO, &c, 1);

		if (read_d == 0)
		{
			free(line_ptr);
			exit(EXIT_SUCCESS);
		}
		line_ptr[i] = c;
		if (line_ptr[0] == '\n')
		{
			free(line_ptr);
			return ("\0");
		}
		if (i >= buffSZ)
		{
			line_ptr = re_alloc(line_ptr, buffSZ, buffSZ + 1);
			if (line_ptr == NULL)
				return (NULL);
		}
	}
	line_ptr[i] = '\0';
	comment_handle(line_ptr);
	return (line_ptr);
}
