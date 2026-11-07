#include <stdio.h>

/**
 * print_table - Prints a multiplication table up to a given size
 * @size: The size of the multiplication table
 */
void print_table(int size)
{
	int row, col;

	for (row = 1; row <= size; row++)
	{
		for (col = 1; col <= size; col++)
		{
			printf("%d ", row * col);
		}
		printf("\n");
	}
}

/* -- DO NOT Modify the code below this line -- */

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	print_table(4);
	return (0);
}
