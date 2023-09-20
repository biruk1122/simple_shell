#include "main.h"
/*
 * free_array_string - string
 * @array: array
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
