#include "shell.h"

/**
 * array_rev - reverses an array.
 *
 * @arr: The wanted array.
 * @len: the length.
 *
 * Return: nothing
 */
void array_rev(char *arr, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}

/**
 * *str_cpy - copies string from  src to dest
 *
 * @dest : buffer pointer
 * @src : string pointer
 *
 * Return: the pointer to dest
 *
*/
char *str_cpy(char *dest, char *src)
{
	int c = 0;

	while (c >= 0)
	{
		dest[c] = src[c];
		if (src[c] == '\0')
			return (dest);
		c++;
	}
	return (dest);
}

/**
 * str_cat - updates pointer value
 *
 * Description:  appends the src string to the dest string.
 *
 * @src: second string to copy from
 * @dest: string to be overwritten
 *
 * Return:  pointer to the resulting string dest.
*/
char *str_cat(char *dest, char *src)
{
	int i, j;

	i = 0;

	while (dest[i] != '\0')
		i++;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = src[j];

	return (dest);
}

/**
 * str_chr - locates a character in a string.
 *
 * @s: a pointer to the string.
 * @c: the character to be searched for.
 *
 * Return: a pointer to the first occurrence of the character in the string,
 *	or NULL if the character is not found.
*/
char *str_chr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			break;
		s++;
	}

	if (*s == c)
		return (s);
	else
		return (NULL);
}

/**
 * str_dup - pointer to the duplicate string.
 *
 * @str: given string.
 *
 * Return: pointer to duplicated string, NULL on fail.
*/
char *str_dup(char *str)
{
	char *dest;
	unsigned int i;

	if (str == NULL)
		return (NULL);

	dest = (char *)malloc((strlen(str)) * sizeof(char));

	if (dest == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		dest[i] = str[i];
	dest[i] = str[i];

	return (dest);
}
