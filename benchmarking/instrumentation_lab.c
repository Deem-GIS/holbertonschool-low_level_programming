#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

/**
 * next_value - Generates the next pseudo-random integer using an LCG
 * @state: Pointer to the current generator state
 *
 * Return: The updated pseudo-random state value
 */
static unsigned int next_value(unsigned int *state)
{
	*state = (*state * 1103515245u) + 12345u;
	return (*state);
}

/**
 * build_dataset - Populates the static dataset array with initial values
 */
static void build_dataset(void)
{
	unsigned int state;
	int i;

	state = SEED_VALUE;

	for (i = 0; i < DATASET_SIZE; i++)
		dataset[i] = (int)(next_value(&state) % 100000);
}

/**
 * process_dataset - Applies arithmetic transformations to each dataset element
 */
static void process_dataset(void)
{
	int i;
	int v;

	for (i = 0; i < DATASET_SIZE; i++)
	{
		v = dataset[i];
		v = (v * 3) + (v / 7) - (v % 11);
		if (v < 0)
			v = -v;
		dataset[i] = v;
	}
}

/**
 * reduce_checksum - Computes a rolling polynomial checksum over the dataset
 *
 * Return: The computed checksum value
 */
static unsigned long reduce_checksum(void)
{
	unsigned long sum;
	int i;

	sum = 0;
	for (i = 0; i < DATASET_SIZE; i++)
		sum = (sum * 131ul) + (unsigned long)dataset[i];

	return (sum);
}

/**
 * main - Instruments and measures execution time across all dataset phases
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long checksum;
	clock_t t0;
	clock_t t1;
	clock_t t2;
	clock_t t3;
	double total_sec;
	double build_sec;
	double process_sec;
	double reduce_sec;

	t0 = clock();
	build_dataset();
	t1 = clock();
	process_dataset();
	t2 = clock();
	checksum = reduce_checksum();
	t3 = clock();

	if (checksum == 0ul)
		printf("impossible\n");

	total_sec = (double)(t3 - t0) / (double)CLOCKS_PER_SEC;
	build_sec = (double)(t1 - t0) / (double)CLOCKS_PER_SEC;
	process_sec = (double)(t2 - t1) / (double)CLOCKS_PER_SEC;
	reduce_sec = (double)(t3 - t2) / (double)CLOCKS_PER_SEC;

	printf("TOTAL seconds: %.6f\n", total_sec);
	printf("BUILD_DATA seconds: %.6f\n", build_sec);
	printf("PROCESS seconds: %.6f\n", process_sec);
	printf("REDUCE seconds: %.6f\n", reduce_sec);

	return (0);
}
