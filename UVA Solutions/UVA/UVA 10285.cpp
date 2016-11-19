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
int dp[101][101];
int g[101][101];
int r, c;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int solve(int x, int y) {
	if (dp[x][y] != -1) {
		return dp[x][y];
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx > -1 && nx < r && ny > -1 && ny < c && g[nx][ny] < g[x][y]) {
			dp[x][y] = max(dp[x][y], solve(nx, ny) + 1);
		}
	}

	if (dp[x][y] == -1) {
		dp[x][y] = 1;
	}
	return dp[x][y];
}

int main() {
	freopen("input.txt", "r", stdin);
	int testcases;
	cin >> testcases;
	string s;
	for (int i = 0; i < testcases; i++) {
		cin >> s;
		cin >> r;
		cin >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> g[i][j];
			}
		}
		memset(dp, -1, sizeof dp);
		int ans = -1;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				ans = max(ans, solve(i, j));
			}
		}
		cout << s << ": " << ans << endl;
	}
	return 0;
}
