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