//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <time.h>
using namespace std;
int n;
long dp[15][65536];
int gridmasks[16];
map<char, int> e;
void setup() {
	e['0'] = 0, e['1'] = 1, e['2'] = 2, e['3'] = 3, e['4'] = 4, e['5'] = 5, e['6'] =
			6, e['7'] = 7, e['8'] = 8, e['9'] = 9, e['A'] = 10, e['B'] = 11, e['C'] =
			12, e['D'] = 13, e['E'] = 14, e['F'] = 15;

}
bool check(int row, int bitmask, int col) {
	if (((gridmasks[col] & (1 << row)) != 0)) {
		return false;
	}
	bool ans = false;
	ans = ans | ((bitmask & (1 << row)) != 0);

	return !ans;
}

int mark(int row, int mask) {
	if (row <= n - 2) {
		mask = mask | (1 << (row + 1));
	}
	if (row > 0) {
		mask = mask | (1 << (row - 1));
	}
	mask = mask | (1 << (row));
	return mask;
}

int unmark(int row, int mask) {
	if (row <= n - 2) {
		mask = mask & ~(1 << (row + 1));
	}
	if (row > 0) {
		mask = mask & ~(1 << (row - 1));
	}
	mask = mask & ~(1 << (row));
	return mask;
}

long long solve(int col, int mask) {
	if (col == n) {
		return 1;
	}
	int newmask = 0;
	long long ans = 0;
	if (dp[col][mask] != -1) {
		return dp[col][mask];
	}
	if (gridmasks[col] == 131071) {
		return dp[col][mask] = solve(col + 1, 0);
	}
	for (int i = 0; i < n; i++) {
		if (check(i, mask, col) == true) {
			newmask = mark(i, newmask);
			ans = ans + solve(col + 1, newmask);
			newmask = unmark(i, newmask);
		}
	}

	return dp[col][mask] = ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	char a[16];
	setup();
	while (gets(a)) {
		memset(dp, -1, sizeof dp);
		memset(gridmasks, 0, sizeof gridmasks);
		n = strlen(a);
		if (n == 0) {
			continue;
		}
		for (int i = 0; i < (int) strlen(a); i++) {
			if (a[i] != '?') {
				gridmasks[i + 1] = gridmasks[i + 1] | mark(e[a[i]] - 1, 0);
				if (i > 0) {
					gridmasks[i - 1] = gridmasks[i - 1] | mark(e[a[i]] - 1, 0);
				}
				gridmasks[i] = 131071;
			}
		}
		bool go = true;
		for (int i = 0; i < (int) strlen(a) - 2; i++) {
			if (a[i] != '?' && a[i + 1] != '?') {
				if (fabs(e[a[i]] - e[a[i + 1]]) <= 1) {
					cout << 0 << endl;
					go = false;
					break;
				}
			}
		}
		if (go == true) {
			cout << solve(0, gridmasks[0]) << endl;
		}
	}
	return 0;
}
