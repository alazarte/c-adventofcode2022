#include<stdio.h>
#include"solve.h"

// comments

int read_input(char *filepath, int size, char fc[size][size])
{
	FILE *f = fopen(filepath, "r");
	if (f == NULL) {
		printf("ERROR: file not found\n");
		return 1;
	}

	int i = 0;
	while (fgets(fc[i++], size, f) != NULL) ;

	return 0;
}

void cleanup(int size, char fc[size][size])
{
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			fc[j][i] = '\0';
		}
	}
}

int main(int argn, char **argv)
{
	if (argn < 2) {
		printf("ERROR: please provide input filepath\n");
		return 1;
	}

	size_t size = 1000;
	char fc[size][size];

	cleanup(size, fc);
	read_input(argv[1], size, fc);

	solve(size, fc);
	return 0;
}
