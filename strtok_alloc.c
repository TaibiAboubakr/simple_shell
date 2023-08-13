#include "main.h"
/**
 * _puts_std - writes the character c to stdout
 * @c: pointer to string
 * @std: file descriptors / standard I/O streams
 * Return: number of characters printed.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _puts_std(int std, char *c)
{
	return (write(std, c, _slen(c)));
}


/**
 * strtok_alloc - Tokenizes a given line and allocates memory for tokens
 * @line: The input line
 * @read: The number of characters read from the line
 *
 * Return: A double pointer to an array of strings containing the tokens
 *         NULL is returned on failure
 */
char **strtok_alloc(char *line, ssize_t read)
{
	int c = 0, i;
	char *tok_cpy, *tok = NULL, **args, *line2;

	if (read == -1)
	{
		if (line)
			free(line);
		p_err_getline();
	}
	if (read > 0 && line[read - 1] == '\n')
		line[read - 1] = '\0';

	line2 = strdup(line);
	if (line2 == NULL)
	{   free(line);
		return (NULL); }

	tok = strtok(line2, " ");
	tok_cpy = tok;
	for (c = 0; tok; c++)
		tok = strtok(NULL, " ");
	args = (char **)malloc(sizeof(char *) * (c + 1));
	if (args == NULL)
	{   free(line2);
		free(line);
		return (NULL);
	}
	tok_cpy = strtok(line, " ");
	for (i = 0; tok_cpy; i++)
	{
		args[i] = tok_cpy;
		tok_cpy = strtok(NULL, " ");
	}
	args[i] = NULL;
	free(line2);
	return (args);
}
