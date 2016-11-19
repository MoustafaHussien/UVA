//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string.h>
using namespace std;
int a[8];
int conditons[20][3];
int n, m;

bool check() {
	for (int i = 0; i < m; i++) {
		int position1, position2;
		for (int j = 0; j < n; j++) {
			if (a[j] == conditons[i][0]) {
				position1 = j;
			}
			if (a[j] == conditons[i][1]) {
				position2 = j;
			}
		}
		int difference = (int) abs(position1 - position2);
		if (conditons[i][2] > 0) {
			if (difference > (int) abs(conditons[i][2])) {
				return false;
			}
		}
		if (conditons[i][2] < 0) {
			if (difference < (int) abs(conditons[i][2])) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	while (1) {
		int count = 0;
		scanf("%d %d", &n, &m);
		if (n == 0) {
			return 0;
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d %d %d", &conditons[i][0], &conditons[i][1],
					&conditons[i][2]);
		}

		for (int i = 0; i < n; i++) {
			a[i] = i;
		}
		do {
			if (check()) {
				count++;
			}
		} while (next_permutation(a, a + n));
		printf("%d\n", count);
		memset(a, 0, 8);
		memset(conditons, 0, sizeof(conditons[0][0]) * m * n);
		count = 0;
	}
	return 0;
}
