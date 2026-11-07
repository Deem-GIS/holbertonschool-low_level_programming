#include <stdio.h>

/**
 * row_sum - Computes the sum of products for a single row
 * @row: The current row number
 * @cols: The number of columns
 *
 * Return: The sum of products for the given row
 */
int row_sum(int row, int cols)
{
	int c;
	int sum = 0;

	for (c = 1; c <= cols; c++)
		sum += row * c;

	return (sum);
}

/**
 * total_sum - Computes the total sum across all rows and columns
 * @rows: The number of rows
 * @cols: The number of columns
 *
 * Return: The total sum of all rows
 */
int total_sum(int rows, int cols)
{
	int r;
	int total = 0;
	int current = 0;

	for (r = 1; r <= rows; r++)
	{
		current = row_sum(r, cols);
		total += current;
	}

	return (total);
}

/* -- DO NOT Modify the code below this line -- */

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	printf("%d\n", total_sum(3, 3));
	return (0);
}
