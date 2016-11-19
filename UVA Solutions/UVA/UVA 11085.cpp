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
int row[8];
int z[8];
int count;

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

void check2() {
	int min = 0;
	for (int i = 0; i < 8; i++) {
		if (row[i] != z[i]) {
			min++;
		}
	}
	if (min < count) {
		count = min;
//		printf("%d %d\n",min,count);
	}

}

void backtracksolve(int rowindex) {
	if (rowindex == 8) {
		check2();
	}
	for (int j = 0; j < 8; j++) {
		if (check(rowindex, j)) {
			row[rowindex] = j;
			backtracksolve(rowindex + 1);
		}
	}
}

int main() {
	int n = 1;
	while (scanf("%d %d %d %d %d %d %d %d", &z[0], &z[1], &z[2], &z[3], &z[4],
			&z[5], &z[6], &z[7]) != EOF) {

		for (int i = 0; i < 8; i++) {
			z[i] = z[i] - 1;
		}
		count = 1000;
		backtracksolve(0);
		printf("Case %d: %d\n", n, count);
		n++;
	}
	return 0;
}


