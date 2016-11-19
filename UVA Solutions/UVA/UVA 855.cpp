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
using namespace std;

int comp(int a, int b) {
	return a > b;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {

		int s, a, f;
		scanf("%d %d %d", &s, &a, &f);
		int x[50010];
		int y[50010];
		for (int i = 0; i < f; i++) {
			scanf("%d %d", &x[i], &y[i]);
		}
		sort(x, x + f);
		sort(y, y + f);

		printf("(Street: %d, Avenue: %d)\n", x[(f - 1) / 2], y[(f - 1) / 2]);
	}
	return 0;
}
