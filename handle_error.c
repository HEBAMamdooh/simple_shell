#include "shell.h"

/**
 * custom_error - handles custom errors.
 *
 * @argv: shell program name.
 * @c: Errors Count.
 * @frscommand: 1st command from read line.
 *
 * Return: nothing
 */
void custom_error(char **argv, int c, char **frscommand)
{
	char *er = _itost(c);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(er);
	PRINTER(": ");
	PRINTER(frscommand[0]);
	PRINTER(": Illegal number: ");
	PRINTER(frscommand[0]);
	PRINTER("\n");
	free(er);
}

/**
 * display_error - display error.
 *
 * @frscommand: 1st command from read line.
 * @c: loop error counter.
 *
 * @argv: Nothing
 */
void display_error(char **argv, int c, char *frscommand)
{
	char *er = _itost(c);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(er);
	PRINTER(": ");
	PRINTER(frscommand);
	PRINTER(": not found\n");
	free(er);
}
