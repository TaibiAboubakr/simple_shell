#include "main.h"
/**
 * non_interactive_shell -function that execute command in non-interactive mode
 * @argv: An array of pointers that contains the command-line arguments
 *	  provided to shell
 */
void non_interactive_shell(char *argv[])
{
char *line = NULL, **args, *cmd, *cmd1;
size_t len = 0;
ssize_t r = 0;
int exit_code = 0, count = 0, child_exit_code = 0, c_exit = 0;

while ((r = getline(&line, &len, stdin)) != -1)
{ exit_code = 0;
count++;
args = strtok_alloc(line, r);
if (args == NULL)
{ _puts_std(2, "Memory allocation failed\n");
free(line);
exit(EXIT_FAILURE);
}
if (!args[0])
{ free(args);
continue; }
if ((_strcmp(args[0], "env")) == 0)
{ _env();
free(args);
exit_code = 0;
continue; }
/*if ((_strcmp(args[0], "exit")) == 0)
{ free(args);
free(line);
exit(child_exit_code); }*/
c_exit = check_if_exit(args, argv[0], count, child_exit_code);
if (c_exit == -2)
{ free(line);
exit (2); }
if (c_exit >= 0)
{free(line);
exit(c_exit);}
cmd1 = check_command_path(args[0]);
if (!cmd1)
cmd = args[0];
if (cmd1)
cmd = cmd1;
if (exit_code = check_file(argv[0], cmd, args, count))
continue;
/* if (!check_file_exist(argv[0], cmd, "not found", count))
{ free(args);
exit_code = 127;
continue; }
if (!check_file_perm(argv[0], cmd, "Permission denied", count))
{free(args);
exit_code = 126;
continue; }*/
child_exit_code = exec_cmd(cmd, args);
_free(NULL, cmd1);
free(args); }
free(line);
exit(exit_code); }


/**
 * main - main function of simple shell
 * @argc: number of argument passed to program
 * @argv: array of pointer that point to each argumrnt passed to program
 * Return: Always 0 on Success.
 */

int main(int argc __attribute__((unused)), char *argv[])
{
char *line = NULL, **args, *cmd, *cmd1 = NULL;
size_t len = 0;
ssize_t read = 0, w;
int count = 0, c_exit = 0;

if (!isatty(STDIN_FILENO))
non_interactive_shell(argv);
while (1)
{ w = write(1, "($) ", 4);
if (w == -1)
p_err_write();
count++;
read = getline(&line, &len, stdin);
args = strtok_alloc(line, read);
if (args == NULL)
{ _puts_std(2, "Memory allocation failed\n");
exit(EXIT_FAILURE);
}
if (!args[0])
{ free(args);
continue; }
c_exit = check_if_exit(args, argv[0], count, 0);
if (c_exit == -2)
{ c_exit = 2;
continue; }
if (c_exit >= 0)
break;
if ((_strcmp(args[0], "env")) == 0)
{ _env();
free(args);
continue; }
cmd1 = check_command_path(args[0]);
if (!cmd1)
cmd = args[0];
if (cmd1)
cmd = cmd1;
if (check_file(argv[0], cmd, args, count))
continue;
/* if (!check_file_exist(argv[0], cmd, "not found", count))
{ free(args);
continue; }
if (!check_file_perm(argv[0], cmd, "Permission denied", count))
{ free(args);
continue; } */
exec_cmd(cmd, args);
_free_with_null(&line, &cmd1);
free(args); }
_free(line, cmd1);
return (c_exit);
}

