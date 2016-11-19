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
int n, m, p[100], f[100];
int dp[201][10000];
int maxf = -1;
int solve(int i, int w) {
	if (w > m && m < 1800)
		return -1000;
	if (w > m + 200)
		return -1000;
	if (i == n) {
		if (w > m && w <= 2000)
			return -1000;
		return 0;
	}
	if (dp[i][w] != -1)
		return dp[i][w];

	return dp[i][w] = max(solve(i + 1, w), f[i] + solve(i + 1, w + p[i]));
}
int main() {
	freopen("input.txt", "r", stdin);
	while (scanf("%d %d", &m, &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &p[i], &f[i]);
		}
		memset(dp, -1, sizeof(dp));
		cout << solve(0, 0) << endl;
	}
	return 0;
}
