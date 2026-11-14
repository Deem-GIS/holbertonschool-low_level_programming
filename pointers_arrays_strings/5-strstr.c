#include "main.h"
#include <stddef.h>

/**
 * _strstr - Locates a substring
 * @haystack: Pointer to the string to search
 * @needle: Pointer to the substring to locate
 *
 * Return: Pointer to the beginning of the located substring,
 * or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	int i;
	int j;

	if (needle[0] == '\0')
		return (haystack);

	for (i = 0; haystack[i] != '\0'; i++)
	{
		j = 0;
		while (needle[j] != '\0' && haystack[i + j] == needle[j])
			j++;

		if (needle[j] == '\0')
			return (haystack + i);
	}

	return (NULL);
}
