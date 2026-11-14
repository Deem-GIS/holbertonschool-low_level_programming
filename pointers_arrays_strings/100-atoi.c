#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: Pointer to the string to convert
 *
 * Return: The converted integer, or 0 if no numbers are present
 */
int _atoi(char *s)
{
	int i;
	int sign;
	int res;
	int started;

	i = 0;
	sign = 1;
	res = 0;
	started = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-' && !started)
		{
			sign = -sign;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			res = (res * 10) - (s[i] - '0');
		}
		else if (started)
		{
			break;
		}
		i++;
	}

	if (sign > 0)
		return (-res);

	return (res);
}
