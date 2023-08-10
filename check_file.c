#include "main.h"
/**
 * check_file_exist - function that check is an given file exist or not ,
 * and print message to stderr if the file not exist
 * @shellname: The name of the shell invoking the function
 * @filename: a pointer to string that contains filename
 * @err_msg: Error message to be displayed if the file is not executable
 * @count: a count associated with the current operation
 * Return: 1 if file exist or 0 if not exist.
 */
int check_file_exist(char *shellname, char *filename, char *err_msg, int count)
{
	int len;
	struct stat f_stat;

	if ((stat(filename, &f_stat) == 0))
		return (1);

	len = _slen(shellname) - 2;
	shellname = shellname + 2;
	_puts_len(2, shellname, len);
	write(2, ": ", 2);
	print_number(count);
	write(2, ": ", 2);
	_puts_len(2, filename, _slen(filename));
	write(2, ": ", 2);
	_puts_len(2, err_msg, _slen(err_msg));
	write(2, "\n", 1);
	return (0);
}

/**
 * check_file_perm - function that check is a given file is executable
 * and print message to stderr if not executable
 * @shellname: The name of the shell invoking the function
 * @filename: a pointer to string that contains filename
 * @err_msg: Error message to be displayed if the file is not executable
 * @count: a count associated with the current operation
 * Return: 1 if file executable or 0 if not executable
 */
int check_file_perm(char *shellname, char *filename, char *err_msg, int count)
{
	int len;
	struct stat f_stat;

	if ((stat(filename, &f_stat) == 0))
		if (f_stat.st_mode & S_IXUSR)
			return (1);

	len = _slen(shellname) - 2;
	shellname = shellname + 2;
	_puts_len(2, shellname, len);
	write(2, ": ", 2);
	print_number(count);
	write(2, ": ", 2);
	_puts_len(2, filename, _slen(filename));
	write(2, ": ", 2);
	_puts_len(2, err_msg, _slen(err_msg));
	write(2, "\n", 1);
	return (0);
}
