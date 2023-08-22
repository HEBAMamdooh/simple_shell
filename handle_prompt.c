#include "shell.h"

/**
 * handle_signal - handle ctrl+c.
 *
 * @n: signal value.
 *
 * Return: Nothing.
 */
void handle_signal(int n)
{
	(void)n;
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_SUCCESS);
}

/**
 * prompt - displays the prompt in shell.
 *
 * Return: nothing.
 */

void prompt(void)
{
	PRINTER("$ ");
}
