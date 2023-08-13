#include "main.h"
/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: s1[i] - s2[i]
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}

/**
 * _strncmp - This function compares at most the first 'n'
 * characters of the two strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: 0 if the two string are identical or number represent the difference
 * between ASCII value of the two first difference char between to strings
 */
int _strncmp(char *s1, char *s2, int n)
{
    int i;
	
    for (i = 0; s1[i] != '\0' && s2[i] != '\0' && n >= i; i++)
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }

    return (s1[i] - s2[i]);
}