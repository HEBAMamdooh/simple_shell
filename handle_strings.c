#include "shell.h"

/**
 * _strcmp - compares two strings
 *
 * @s1: 1st string.
 * @s2: 2nd string.
 *
 * Return:  integer.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}

	if (s1[i] == s2[i])
		return (0);
	return (s1[i] - s2[i]);
}

/**
 * str_cmp - compares n chars of s1 and s2.
 *
 * @s1: 1st string.
 * @s2: 2nd string.
 * @n: number of chars to read.
 *
 * Return: integer.
 */
int str_cmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
		return (-1);

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * _isalpha - returns 1 if c is a letter
 *
 * @c: character to be checked if a letter, lowercase or uppercase
 *
 * Return: 1 if letter, 0 otherwise
*/
int _isalpha(int c)
{
	if (((c <= 90) && (c >= 65)) | ((c >= 97) && (c <= 122)))
		return (1);
	else
		return (0);
}

/**
 * num_len - counts the digit length of a number.
 *
 * @num: length counter.
 *
 * Return: A number.
 */
int num_len(int num)
{
	unsigned int num1;
	int len = 1;

	if (num < 0)
	{
		len++;
		num1 = num * -1;
	}
	else
		num1 = num;

	while (num1 > 9)
	{
		len++;
		num1 /= 10;
	}
	return (len);
}

/**
 * _itost - converts int to string
 *
 * @num: integer to convert.
 *
 * Return: converted string.
 */
char *_itost(int num)
{
	char *buffer;
	int len = num_len(num);
	unsigned int num1;

	buffer = malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);
	buffer[len] = '\0';

	if (num < 0)
	{
		num1 = num * -1;
		buffer[0] = '-';
	}
	else
	{
		num1 = num;
	}

	len--;
	do {
		buffer[len] = (num1 % 10) + '0';
		num1 /= 10;
		len--;
	} while (num1 > 0);

	return (buffer);
}
