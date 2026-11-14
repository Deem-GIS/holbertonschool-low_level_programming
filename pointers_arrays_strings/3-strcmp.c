#include "main.h"

/**
 * _strcmp - Compares two strings
 * @s1: Pointer to the first string
 * @s2: Pointer to the second string
 *
 * Return: Negative if s1 < s2, 0 if equal, positive if s1 > s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}

	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
