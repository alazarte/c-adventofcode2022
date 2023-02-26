#include<stdio.h>
#include<string.h>

void fill_array(size_t size, char *arr, char with)
{
	size_t i;
	for (i = 0; i < size; i++)
		arr[i] = with;
	arr[size - 1] = '\0';
}

void cranes_in_row(char *line, char *row)
{
	int i = 0;
	while (*line != '\0') {
		row[i++] = *(line + 1);
		line += 4;
	}
}

void push(char *to, char c)
{
	char tmp = *to;		// tmp=a
	char next = *(to + 1);

	*to = c;
	while (tmp != '\0') {
		to++;
		*to = tmp;
		tmp = next;
		next = *(to + 1);
	}
}

void poplastn(char *s, int n, char *into)
{
	while (*(s + 1) != '\0')
		s++;
	strcpy(into, s - (n - 1));
	*(s - (n - 1)) = '\0';
}

void appendchar(char *to, char c)
{
	while (*to != '\0')
		to++;
	*to = c;
	to++;
	*to = '\0';
}

void clean_array(char *r)
{
	while (*r != '\0')
		*r++ = '\0';
}

void operate(size_t size, char cranes[size][size], int move, int from, int to)
{
	int i;

	if (cranes[from][0] == '\0')	// no cranes left to move
		return;
	char last[move + 1];
	poplastn(cranes[from], move, last);

	for (i = 0; i <= move; i++)
		appendchar(cranes[to], last[i]);
}

void last_cranes(size_t size, char cranes[size][size], char last[size])
{
	size_t i;
	for (i = 0; i < size; i++) {
		char c;
		poplastn(cranes[i], 1, &c);
		last[i] = c;
	}
}

void init_cranes(size_t size, char cranes[size][size])
{
	size_t i;
	for (i = 0; i < size; i++)
		fill_array(size, cranes[i], '\0');
}

void print_cranes(size_t size, char cranes[size][size])
{
	size_t i;
	for (i = 0; i < size; i++) {
		if (cranes[i][0] == '\0')
			continue;
		printf("c%ld: %s\n", i, cranes[i]);
	}
}

void print_top_cranes(size_t size, char cranes[size][size])
{
	size_t i;
	char last[size];
	fill_array(size, last, ' ');
	last_cranes(size, cranes, last);

	printf("Last cranes: ");
	for (i = 0; i < size; i++) {
		printf("%c", last[i]);
	}
	printf("\n");
}

void push_cranes(size_t size, char cranes[size][size], char row[size])
{
	int i = 0;
	while (row[i] != '\0') {
		if (row[i] != ' ')
			push(cranes[i], row[i]);
		i++;
	}
}

void solve(size_t size, char input[size][size])
{
	size_t i, j;
	char cranes[size][size];
	char row[size];

	init_cranes(size, cranes);

	for (j = 0; j < size; j++) {
		// found column number
		if (input[j][1] == '1')
			break;

		cranes_in_row(input[j], row);
		push_cranes(size, cranes, row);
		clean_array(row);
	}

	print_cranes(size, cranes);
	printf("----\n");
	// j is the line of column numbers, also skip blank line
	for (i = j + 2; i < size && input[i][0] != '\0'; i++) {
		int move, from, to;
		sscanf(input[i], "move %d from %d to %d", &move, &from, &to);
		operate(size, cranes, move, from - 1, to - 1);
	}
	print_cranes(size, cranes);
	print_top_cranes(size, cranes);
}
