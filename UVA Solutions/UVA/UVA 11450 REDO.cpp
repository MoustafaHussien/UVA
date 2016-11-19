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
	int tc, m, c;
	bool can_reach[205][25];
	int price[25][25];
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &m, &c);
		for (int i = 0; i < c; i++) {
			scanf("%d", &price[i][0]);
			for (int j = 1; j <= price[i][0]; j++)
				scanf("%d", &price[i][j]);
		}
		memset(can_reach, false, sizeof(can_reach));
		for (int i = 1; i <= price[0][0]; i++) {
			if (m - price[0][i] >= 0) {
				can_reach[m - price[0][i]][0] = true;
			}
		}
		for (int j = 1; j < c; j++)
			for (int i = 0; i < m; i++)
				if (can_reach[i][j - 1]) {
					for (int l = 1; l <= price[j][0]; l++) {
						if (i - price[j][l] >= 0) {
							can_reach[i - price[j][l]][j] = true;
						}
					}
				}
		int i;
		for (i = 0; i <= m; i++) {
			if (can_reach[i][c - 1])
				break;
		}
		if (i == m + 1)
			printf("no solution\n");
		else
			printf("%d\n", m - i);
	}
	return 0;
}
