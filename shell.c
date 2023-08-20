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
int exit_code = 0, count = 0, child_exit_code = 0, c_exit = 0, env = 0, f = 0;
while ((r = getline(&line, &len, stdin)) != -1)
{ exit_code = 0;
count++;
args = strtok_alloc(line, r);
if (args == NULL)
continue;
env = check_is_env_cd(args, argv[0], count, child_exit_code);
if (env)
{
if (env == 2)
f = 2;
exit_code = 0;
continue; }
c_exit = check_if_exit(args, argv[0], count, child_exit_code);
if (c_exit == -2)
{ free(line);
exit(2); }
if (c_exit >= 0)
{free(line);
exit(c_exit); }
cmd1 = check_command_path(args[0]);
cmd = !cmd1 ? args[0] : cmd1;
exit_code = check_file(argv[0], cmd, args, count);
if (exit_code)
continue;
child_exit_code = exec_cmd(cmd, args);
_free(NULL, cmd1);
free(args); }
free(line);
if (f == 2)
free_env(environ);
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
int count = 0, c_exit = 0, env = 0, f = 0;
if (argc == 2)
input_file_shell(argv);
if (!isatty(STDIN_FILENO))
non_interactive_shell(argv);
while (1)
{ w = write(1, "($) ", 4);
p_err_write(w);
count++;
read = getline(&line, &len, stdin);
args = strtok_alloc(line, read);
if (args == NULL)
continue;
c_exit = check_if_exit(args, argv[0], count, 0);
if (c_exit == -2)
{ c_exit = 2;
continue; }
if (c_exit >= 0)
break;
env = check_is_env_cd(args, argv[0], count, c_exit);
if (env)
{
if (env == 2)
f = 2;
continue; }
cmd1 = check_command_path(args[0]);
cmd = !cmd1 ? args[0] : cmd1;
if (check_file(argv[0], cmd, args, count))
continue;
exec_cmd(cmd, args);
_free_with_null(&line, &cmd1);
free(args); }
_free(line, cmd1);
if (f == 2)
free_env(environ);
return (c_exit);
}

