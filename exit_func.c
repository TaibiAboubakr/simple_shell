#include "main.h"

/**
 * check_if_exit - Checks for the "exit" command and handles its argument
 * @args: An array of strings containing command-line arguments
 * @shellname: The name of the shell program
 * @count: The current command count
 * Return:  0, if no additional argument is provided
 * -2, displaying an error message if a non-valid integer argument is provided
 * The integer exit status, if a valid integer argument is provided
 * 0,if the given command is not "exit"
 */

int check_if_exit(char **args, char *shellname, int count)
{
	int r_atoi = 0;

	if (_strcmp(args[0], "exit") == 0)
	{
		if (!args[1])
		{ free(args);
		return (0); }
		r_atoi = _atoi(args[1]);
		if (r_atoi == -1)
		{
			_puts_len(2, shellname, _slen(shellname));
			write(2, ": ", 2);
			print_number(2, count);
			write(2, ": ", 2);
			_puts_len(2, "exit", _slen("exit"));
			write(2, ": ", 2);
			_puts_len(2, "Illegal number", _slen("Illegal number"));
			write(2, ": ", 2);
			_puts_len(2, args[1], _slen(args[1]));
			write(2, "\n", 1);
			free(args);
			return (-2);
		}
		free(args);
		return (r_atoi);
	}
	return (-1);
}

