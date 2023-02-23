#include<stdio.h>

int atoi(char *s)
{
	int n = 0;
	while (*s != '\0' && *s >= '0' && *s <= '9') {
		n = n * 10 + (*s - '0');
		s++;
	}
	return n;
}

void split(char at, char *input, char first[100], char second[100])
{
	char *s = input;

	int i = 0;
	while (*s != '\0' && *s != at) {
		first[i++] = *s++;
	}
	first[i] = '\0';
	s++;
	i=0;

	while (*s != '\0') {
		second[i++] = *s++;
	}
	second[i] = '\0';
}

void parse_start_end(char *s, int *start, int *end)
{
	char first[100];
	char second[100];

	split('-', s, first, second);
	*start = atoi(first);
	*end = atoi(second);
}

int print_fully_contained(char *line)
{
	char first[100];
	char second[100];
	split(',', line, first, second);

	int start1, end1, start2, end2;
	parse_start_end(first, &start1, &end1);
	parse_start_end(second, &start2, &end2);

	// xxx....
	// ..xx....
	// end1 >= start2
	// end2 >= start1

	if ((start1 >= start2 && start1 <= end2) || \
			(start2 >= start1 && start2 <= end1))
		return 1;
	return 0;
}

int solve(int size, char fc[size][size])
{
	int i;
	int res = 0;
	for (i = 0; i < size && fc[i][0] != '\0'; i++) {
		res += print_fully_contained(fc[i]);
	}
	printf("%d pairs overlap\n", res);
	return 0;
}
