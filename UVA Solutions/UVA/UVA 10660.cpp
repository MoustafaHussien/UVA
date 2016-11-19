//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
using namespace std;
int a[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
		1, 1, };
int result[25];
int population[5][5] = { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } };

int calculatecost() {
	int cost = 0;
	int x, y;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (population[i][j] != 0) {
				for (int k = 0; k < 25; k++) {
					if (a[k] == 1) {
						x = k / 5;
						y = k % 5;
						cost =
								cost
										+ (population[i][j]
												* (abs(x - i) + abs(y - j)));
					}
				}
			}
		}
	}
	return cost;
}

int main() {
	int n, x, y, c;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &x, &y, &c);
		population[x][y] = c;
	}
	int cost = 1000000;
	int temp;
	do {
		temp = calculatecost();
		if (temp < cost) {
			cost = temp;
			copy(a, a + 25, result);
		}
	} while (next_permutation(a, a + 25));
	printf("\n");
	for (int i = 0; i < 25; i++) {
		if (result[i] == 1) {
			printf("%d ", i);
		}
	}
	printf("\n%d", temp);
	return 0;
}
