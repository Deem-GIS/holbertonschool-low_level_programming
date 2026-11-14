#include "main.h"

/**
 * is_separator - Checks if a character is a word separator
 * @c: Character to check
 *
 * Return: 1 if separator, 0 otherwise
 */
int is_separator(char c)
{
	char sep[] = " \t\n,;.!?\"(){}";
	int i;

	for (i = 0; sep[i] != '\0'; i++)
	{
		if (c == sep[i])
			return (1);
	}
	return (0);
}

/**
 * cap_string - Capitalizes all words of a string
 * @s: Pointer to the string to modify
 *
 * Return: Pointer to the resulting string
 */
char *cap_string(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			if (i == 0 || is_separator(s[i - 1]))
				s[i] -= 32;
		}
		i++;
	}

	return (s);
}
