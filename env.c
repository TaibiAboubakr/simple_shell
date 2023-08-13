include "main.h"
/**
 * _env - function that prints all environment variables
 */
void _env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{	_puts(environ[i]);
		__putchar('\n');
	}
}
/**
 * _getenv - Retrieve the value of an environment variable
 * @var: The name of the environment variable
 *
 * Return: If the variable is found, a pointer to its value is returned.
 *         Otherwise a NULL is returned
 */
char *_getenv(char *var)
{
	int i;
	int len = _slen(var);

	for (i = 0; environ[i]; i++)
	{

		if (_strncmp(environ[i], var, len) == 0 && environ[i][len] == '=')
		{
			return (&environ[i][len + 1]);
		}
	}
	return (NULL);
}

