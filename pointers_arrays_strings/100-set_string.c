#include "main.h"

/**
 * set_string - Sets the value of a pointer to a char
 * @s: Double pointer to the char pointer to update
 * @to: Pointer to the target string
 */
void set_string(char **s, char *to)
{
	*s = to;
}
