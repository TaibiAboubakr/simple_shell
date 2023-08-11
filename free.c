#include "main.h"
/**
 * _free - Frees the occupied memory by the char pointers and sets them to NULL
 * @a: pointer to a character array
 * @b: another character array
 */
void _free(char *a, char *b)
{
	if (b)
		free(b);
	b = NULL;

	if (a)
		free(a);
	a = NULL;
}

