//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int n;
	//freopen("input.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		int a[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &a[i][j]);
				if (j > 0)
					a[i][j] += a[i][j - 1];
				if (i > 0)
					a[i][j] += a[i - 1][j];
				if (i > 0 && j > 0)
					a[i][j] -= a[i - 1][j - 1];
			}
		}
		int ans = -999999999;
		int x;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = i; k < n; k++)
					for (int l = j; l < n; l++) {
						x = a[k][l];
						if (j > 0)
							x -= a[k][j - 1];
						if (i > 0)
							x -= a[i - 1][l];
						if (i > 0 && j > 0) {
							x += a[i - 1][j - 1];
						}
						ans = max(ans, x);
					}
		printf("%d\n", ans);
	}
	return 0;
}
