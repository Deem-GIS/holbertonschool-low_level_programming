#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates a random valid password for the 101-crackme program
 *
 * Return: Always 0
 */
int main(void)
{
	int sum;
	int rem;
	char c;

	srand(time(NULL));
	sum = 0;

	while (2772 - sum > 170)
	{
		c = (rand() % 75) + 48;
		sum += c;
		putchar(c);
	}

	rem = 2772 - sum;
	if (rem > 122)
	{
		putchar(48);
		rem -= 48;
	}
	putchar(rem);

	return (0);
}
