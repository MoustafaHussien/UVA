//============================================================================
// n*name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int n;
int grid[9][9];
bool notfound = true;

bool noConflicts(int row, int col, int num) {
	for (int i = 0; i < n * n; i++) {
		if (grid[row][i] == num) {
			return false;
		}
		if (grid[i][col] == num) {
			return false;
		}
	}
	int x = row / n;
	x = x * n;
	int y = col / n;
	y = y * n;
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (grid[i][j] == num) {
				return false;
			}
		}
	}
	return true;
}

void solve(int row, int col) {
	if (col == n * n) {
		col = 0;
		row++;
	}
	if (row == n * n) {
		for (int i = 0; i < n * n; i++) {
			for (int j = 0; j < n * n; j++) {
				if (j != 0)
					printf(" ");
				printf("%d", grid[i][j]);
			}
			printf("\n");
		}
		notfound = true;
		printf("-----------------------------------------------\n");
		return;
	}

	if (notfound && grid[row][col] == 0) {
		for (int i = 1; notfound && i < ((n * n) + 1); i++) {
			if (!noConflicts(row, col, i))
				continue;
			grid[row][col] = i;
			solve(row, col + 1);
			grid[row][col] = 0;
		}
	} else if (notfound) {
		solve(row, col + 1);
	}
}

int main() {
	bool line = false;
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n * n; i++) {
			for (int j = 0; j < n * n; j++) {
				scanf("%d", &grid[i][j]);
			}
		}
		if (line) {
			printf("\n");
		} else {
			line = true;
		}
		solve(0, 0);
		if (notfound) {
			printf("NO SOLUTION\n");
		}
		notfound = true;
	}
	return 0;
}
