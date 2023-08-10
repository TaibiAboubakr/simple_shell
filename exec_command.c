#include "main.h"
/**
 * exec_cmd - Execute a command with arguments
 * @args: An array of strings representing the command and its arguments
 */
void exec_cmd(char *args[])
{
	int status;
	pid_t child_pid, term_ch_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
			perror("execve");
	}
	else
	{
		term_ch_pid = waitpid(child_pid, &status, 0);
		if (term_ch_pid == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}
}

