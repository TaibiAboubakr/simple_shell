#include "main.h"
/**
 * check_command_path - Find the full path to an executable command
 * @cmd: The command string to locate the executable for
 * Return: An allocated string containing the full path to the executable
 *         or NULL if the executable is not found
 */
char *check_command_path(char *cmd)
{
	char *path, *path_dup, *token, *file_path = NULL;
	size_t cmd_len, dir_len;
	struct stat f_stat;

	if (cmd[0] == '/' || cmd[1] == '/')
		return (NULL);
	path = getenv("PATH");
	if (path == NULL)
	{   write(2, "PATH not exist", 14);
		exit(1);
	}
	if (path[0] =='\0')
		return (NULL);
	path_dup = strdup(path);
	cmd_len = strlen(cmd);
	token = strtok(path_dup, ":");
	while (token)
	{
		dir_len = strlen(token);
		file_path = malloc(cmd_len + dir_len + 2);
		strcpy(file_path, token);
		strcat(file_path, "/");
		strcat(file_path, cmd);
		strcat(file_path, "\0");
		if ((stat(file_path, &f_stat) == 0))
		{
			free(path_dup);
			return (file_path);
		}
		token = strtok(NULL, ":");
		free(file_path);
		file_path = NULL;
	}
	free(path_dup);
	if (file_path)
		free(file_path);
	return (NULL);
}

