#include "main.h"

extern char **environ;
/**
 * main - main function of simple shell
 * @argc: number of argument passed to program
 * @argv: array of pointer that point to each argumrnt passed to program 
 * Return: Always 0 on Success.
 */

int main(int argc, char *argv[]){
char *line = NULL, *flags = NULL, *args[64] = {NULL};
size_t len = 0;
ssize_t read = 0, w;
pid_t child_pid, term_ch_pid;
int i, status, exit_ch, count = 0;

(void)exit_ch;
(void)argc;
while (1)
{
w = write (1, "($) ", 4);
if (w == -1)
{
perror("write");
exit(EXIT_FAILURE);
}
count++;
read = getline(&line, &len, stdin);
if (read == -1)
{write (1, "\n", 1);
if (errno != 0 && errno != EOF) {
perror("getline");
exit(EXIT_FAILURE);
}
exit(0);
}

if (line[read - 1] == '\n') {
    line[read - 1] = '\0';
}
if (read == 0) {
    line[0] = '\0';
}

flags = strtok(line, " ");
for(i = 0; flags; i++)
{
args[i] = flags;
flags = strtok(NULL, " ");
}
args[i] = NULL;
if (args[0] && (strcmp(args[0], "exit")) == 0)
break;

if(args[0])
{
if (!check_file_exist(argv[0], args[0], "not found", count))
continue;
if (!check_file_perm(argv[0], args[0], "Permission denied", count))
continue;
}
if (args[0])
{
child_pid = fork();

if (child_pid == -1)
{
    perror("fork");
        return (1);
}
        
if (child_pid == 0)
{
if (execve(args[0], args, environ) == -1)
    {
    perror("./shell");
    }
}
else {
term_ch_pid = waitpid(child_pid, &status, 0);
/* printf("\nAfter child[%d] process ID is : %d\n",i, getpid());
 */
if (term_ch_pid == -1)
{
perror("waitpid");
return (1);
}
if (WIFEXITED(status))
exit_ch = WEXITSTATUS(status);
/* printf("exit status is %d\n",exit_ch); */
}
}
if (line)
free(line);
line = NULL;

}
free(line);


return (0);
}

