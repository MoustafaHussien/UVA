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
int n, m, x, y;
char grid[21][21];
bool visits[21][21];
char land;
int count;
void dfs1(int a, int b) {
	visits[a][b] = true;
	if (a > 0 && !visits[a - 1][b] && grid[a - 1][b] != land) {
		count++;
		dfs1(a - 1, b);
	}
	if (a < m - 1 && !visits[a + 1][b] && grid[a + 1][b] != land) {
		count++;
		dfs1(a + 1, b);
	}
	if (b < m - 1 && !visits[a][b + 1] && grid[a][b + 1] != land) {
		count++;
		dfs1(a, b + 1);
	}
	if (b > 0 && !visits[a][b - 1] && grid[a][b - 1] != land) {
		count++;
		dfs1(a, b - 1);
	}
	if (b == 0 && !visits[a][n - 1] && grid[a][n - 1] != land) {
		count++;
		dfs1(a, n - 1);
	}
	if (b == n - 1 && !visits[a][0] && grid[a][0] != land) {
		count++;
		dfs1(a, 0);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	while (scanf("%d %d", &m, &n) != EOF) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				scanf("%c", &grid[i][j]);
		}
		scanf("%d %d", &x, &y);
		memset(visits, false, sizeof(visits));
		land = grid[x][y];
		dfs1(x, y);
		count = 0;
		int ans = -1;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (!visits[i][j] && grid[i][j] != land) {
					count = 0;
					dfs1(i, j);
					ans = max(ans, count);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
