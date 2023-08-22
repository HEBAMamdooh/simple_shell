#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * file_reader - read command from file
 * @fl: name of file
 * @argv: shell program name
 * Return: exits with value 0
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
			handle_file(line, i, fp, argv);
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