#include "main.h"
/**
 * _env - function that prints all environment variables.
 */
void _env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{	_puts(environ[i]);
		__putchar('\n');
	}
}

