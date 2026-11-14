#include "main.h"
#include <stddef.h>

/**
 * _strchr - Locates a character in a string
 * @s: Pointer to the string to search
 * @c: Character to locate
 *
 * Return: Pointer to the first occurrence of c in s, or NULL if not found
 */
char *_strchr(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}

	if (c == '\0')
		return (s + i);

	return (NULL);
}
