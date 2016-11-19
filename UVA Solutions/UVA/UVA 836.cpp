//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>     /* atoi */
#include <string.h>
using namespace std;

int main() {
	int tc;
	freopen("input.txt", "r", stdin);
	scanf("%d\n", &tc);
	char a[30];
	int b[26][26];
	for (int t = 0; t < tc; t++) {
		int n;
		int row = 0;
		while (gets(a) && a[0]) {
			if (strlen(a) == 0) {
				break;
			}
			n = strlen(a);
			for (int i = 0; i < n; i++) {
				if (a[i] == '1') {
					b[row][i] = 1;
				} else {
					b[row][i] = -999;
				}
			}
			row++;
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < n; j++) {
				if (i > 0)
					b[i][j] += b[i - 1][j];
				if (j > 0)
					b[i][j] += b[i][j - 1];
				if (i > 0 && j > 0)
					b[i][j] -= b[i - 1][j - 1];
			}
		}
		int cursum;
		int maxsum = -999;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = i; k < row; k++)
					for (int l = j; l < n; l++) {
						cursum = b[k][l];
						if (i > 0)
							cursum -= b[i - 1][l];
						if (j > 0)
							cursum -= b[k][j - 1];
						if (i > 0 && j > 0)
							cursum += b[i - 1][j - 1];
						maxsum = max(maxsum, cursum);
					}
			}
		}
		if (t) {
			printf("\n");
		}
		if (maxsum < 0)
			cout << "0" << endl;
		else {
			cout << maxsum << endl;
		}

	}
	return 0;
}
