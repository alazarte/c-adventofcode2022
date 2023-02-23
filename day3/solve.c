#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LINE_LEN 100

char find_repeat(char *input)
{
	int len = strlen(input);
	int i, j;
	for (i = 0; i < len / 2; i++) {
		for (j = len / 2; j < len; j++) {
			if (input[i] == input[j]) {
				return input[i];
			}
		}
	}

	return '\0';
}

char find_badge(int size, char line1[size], char line2[size], char line3[size]) {
	// for every c in lines[0]
	// if c not found in lines[1] then skip
	// if c not found in lines[2] then skip
	// else all above is c

	int i, j, k;
	for (i=0; i<LINE_LEN; i++) {
		for (j=0; j<LINE_LEN; j++) {
			if (line1[i] == line2[j]) {
				for (k=0; k<LINE_LEN; k++) {
					if (line2[j] == line3[k]) {
						return line3[k];
					}
				}
				// break out of loop for line 2, letter can be found again
				// in line 2 and again search in vane on line 3
				break;
			}
		}
	}
	return '\0';
}

int priority(char c)
{
	if (c >= 97) {
		return c - 'a' + 1;
	}
	return c - 'A' + 1 + priority('z');
}

void clean(char group[3][100]) {
	int i;
	for(i=0; i<100; i++) {
		group[0][i] = '\0';
		group[1][i] = '\0';
		group[2][i] = '\0';
	}
}

int solve(int size, char input[size][size])
{
	int acc = 0;
	int i = 0;
	for(i=0; i<size && input[i][0] != '\0'; i+=3)
		acc += priority(find_badge(size, input[i], input[i+1], input[i+2]));

	printf("%d\n", acc);

	return 0;
}
