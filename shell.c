#include "main.h"

/**
 * main - main function of simple shell
 * @argc: number of argument passed to program
 * @argv: array of pointer that point to each argumrnt passed to program
 * Return: Always 0 on Success.
 */

int main(int argc __attribute__((unused)), char *argv[])
{
char *line = NULL, *flags = NULL, *args[64] = {NULL};
size_t len = 0;
ssize_t read = 0, w;
int i, count = 0;

while (1)
{
w = write(1, "($) ", 4);
if (w == -1)
p_err_write();
count++;
read = getline(&line, &len, stdin);
if (read == -1)
p_err_getline();
if (line[read - 1] == '\n')
line[read - 1] = '\0';
if (read == 0)
line[0] = '\0';
flags = strtok(line, " ");
for (i = 0; flags; i++)
{
args[i] = flags;
flags = strtok(NULL, " ");
}
args[i] = NULL;
if (!args[0])
continue;
if ((strcmp(args[0], "exit")) == 0)
break;
if (!check_file_exist(argv[0], args[0], "not found", count))
continue;
if (!check_file_perm(argv[0], args[0], "Permission denied", count))
continue;
exec_cmd(args);
if (line)
free(line);
line = NULL;
}
free(line);
return (0);
}

