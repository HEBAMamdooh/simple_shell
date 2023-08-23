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
