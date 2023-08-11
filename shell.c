#include "main.h"
/**
 * non_interactive_shell -function that execute command in non-interactive mode
 * @argv: An array of pointers that contains the command-line arguments
 *	  provided to shell
 */
void non_interactive_shell(char *argv[])
{
char *line = NULL, *flags = NULL, *args[64] = {NULL}, *cmd, *cmd1;
size_t len = 0;
ssize_t read = 0;
int i;

read = getline(&line, &len, stdin);
if (read == -1)
{
if (line)
free(line);
p_err_getline(); }
if (read > 0 && line[read - 1] == '\n')
line[read - 1] = '\0';
flags = strtok(line, " ");
for (i = 0; flags; i++)
{ args[i] = flags;
flags = strtok(NULL, " "); }
args[i] = NULL;
if (!args[0])
exit(0);
if ((strcmp(args[0], "exit")) == 0)
{free(line);
exit(0); }
cmd1 = check_command_path(args[0]);
if (!cmd1)
cmd = args[0];
if (cmd1)
cmd = cmd1;
if (!check_file_exist(argv[0], cmd, "not found", 1))
{free(line);
exit(127); }
if (!check_file_perm(argv[0], cmd, "Permission denied", 1))
{free(line);
exit(126); }
exec_cmd(cmd, args);
_free(line, cmd1);
exit(0);
}


/**
 * main - main function of simple shell
 * @argc: number of argument passed to program
 * @argv: array of pointer that point to each argumrnt passed to program
 * Return: Always 0 on Success.
 */

int main(int argc __attribute__((unused)), char *argv[])
{
char *line = NULL, *flags = NULL, *args[64] = {NULL}, *cmd, *cmd1 = NULL;
size_t len = 0;
ssize_t read = 0, w;
int i, count = 0;

if (!isatty(STDIN_FILENO))
non_interactive_shell(argv);
while (1)
{
w = write(1, "($) ", 4);
if (w == -1)
p_err_write();
count++;
read = getline(&line, &len, stdin);
if (read == -1)
{
_free(line, NULL);
p_err_getline(); }
if (read > 0 && line[read - 1] == '\n')
line[read - 1] = '\0';
flags = strtok(line, " ");
for (i = 0; flags; i++)
{args[i] = flags;
flags = strtok(NULL, " "); }
args[i] = NULL;
if (!args[0])
continue;
if ((strcmp(args[0], "exit")) == 0)
break;
cmd1 = check_command_path(args[0]);
if (!cmd1)
cmd = args[0];
if (cmd1)
cmd = cmd1;
if (!check_file_exist(argv[0], cmd, "not found", count))
{continue; }
if (!check_file_perm(argv[0], cmd, "Permission denied", count))
{continue; }
exec_cmd(cmd, args);
_free(line, cmd1); }
_free(line, cmd1);
return (0);
}
