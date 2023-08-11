#include "main.h"
/**
 * p_err_getline - function that print error when getline function failed
 */
int p_err_getline(void)
{

if (errno == 0)
{
exit (0);
}
if (errno != 0 && errno == EOF)
{
exit(0);
}
write(1, "\n", 1);
if (errno != 0 && errno != EOF)
{
exit(1);
}
exit(0);
}

/**
 * p_err_write - function that print error when write sys call failed
 */
void p_err_write(void)
{
perror("write");
exit(EXIT_FAILURE);

}

