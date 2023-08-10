#include "main.h"
/**
 * p_err_getline - function that print error when getline function failed
 */
void p_err_getline(void)
{
if (errno == 0)
{
return;
}
write(1, "\n", 1);
if (errno != 0 && errno != EOF)
{
exit(EXIT_FAILURE);
}
}

/**
 * p_err_write - function that print error when write sys call failed
 */
void p_err_write(void)
{
perror("write");
exit(EXIT_FAILURE);

}

