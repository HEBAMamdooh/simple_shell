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
