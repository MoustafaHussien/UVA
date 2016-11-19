//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
int x, y, TC;
int row[8];
int count = 1;
bool check(int rowindex, int rowvalue) {
	for (int i = 0; i < rowindex; i++) {
		if (row[i] == rowvalue) {
			return false;
		}
		if (abs(i - rowindex) == abs(row[i] - rowvalue)) {
			return false;
		}
	}
	return true;
}

void backtracksolve(int rowindex) {
	if (rowindex == 8 && row[y] == x) {
		printf("%2d      %d", count++, row[0] + 1);
		for (int j = 1; j < 8; j++)
			printf(" %d", row[j] + 1);
		printf("\n");
	}
	for (int j = 0; j < 8; j++) {
		if (check(rowindex, j)) {
			row[rowindex] = j;
			backtracksolve(rowindex + 1);
		}
	}
}

int main() {
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d %d", &x, &y);
		x--;
		y--;         // switch to 0-based indexing
		memset(row, 0, sizeof row);
		count = 1;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		backtracksolve(0);       // generate all possible 8! candidate solutions
		if (TC) {
			printf("\n");
		}
	}
} // return 0;
