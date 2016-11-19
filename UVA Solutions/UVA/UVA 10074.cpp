//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int a[101][101];
	while (true) {
		int n, m;
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) {
			return 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &a[i][j]);
				if (a[i][j] == 0) {
					a[i][j] = 1;
				} else {
					a[i][j] = -999;
				}
				if (i > 0)
					a[i][j] += a[i - 1][j];
				if (j > 0)
					a[i][j] += a[i][j - 1];
				if (i > 0 && j > 0)
					a[i][j] -= a[i - 1][j - 1];
			}
		}

		long long cursum;
		long long maxsum = -999;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = i; k < n; k++)
					for (int l = j; l < m; l++) {
						cursum = a[k][l];
						if (i > 0)
							cursum -= a[i - 1][l];
						if (j > 0)
							cursum -= a[k][j - 1];
						if (i > 0 && j > 0)
							cursum += a[i - 1][j - 1];
						maxsum = max(maxsum, cursum);
					}
			}
		}
		if (maxsum < 0)
			cout << "0" << endl;
		else {
			cout << maxsum << endl;
		}
	}
	return 0;
}
