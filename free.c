#include "main.h"
/**
 * free_array_string - the free arry string
 * @array: array of the func
 * Void: to void the func
 */

void free_array_string(char **array)
{
	int i = 0;

	if (array == NULL)
		return;
	for (; array[i] != NULL; i++)
	{
		free(array[i]);
	}
}
