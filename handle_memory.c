#include "shell.h"

/**
 * re_alloc - resize memory block reserved by a pointer.
 *
 * @old_size: old size of the memory block.
 * @ptr: pointer to memory block.
 * @new_size: new size to replace the old_size memory block.
 *
 * Return: memory block on success,
 *		NULL on fail.
 */
void *re_alloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *memory;
	char *copy_ptr, *fill;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		memory = malloc(new_size);
		if (memory == NULL)
			return (NULL);

		return (memory);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	copy_ptr = ptr;
	memory = malloc(sizeof(*copy_ptr) * new_size);
	if (memory == NULL)
	{
		free(ptr);
		return (NULL);
	}

	fill = memory;

	for (i = 0; i < old_size && i < new_size; i++)
		fill[i] = *copy_ptr++;

	free(ptr);
	return (memory);
}
