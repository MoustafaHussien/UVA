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
#include <map>
using namespace std;
int tc, m, c;
int price[25][25];
int dp[205][25];
int solve(int money, int g) {
	if (money < 0) {
		return -999999999;
	}
	if (g == c) {
		return m - money;
	}
	if (dp[money][g] != -1)
		return dp[money][g];
	int ans = -9999999;
	for (int i = 1; i <= price[g][0]; i++)
		ans = max(ans, solve(money - price[g][i], (g + 1)));
	return dp[money][g] = ans;
}

int main() {
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%d %d", &m, &c);
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < c; i++) {
			scanf("%d", &price[i][0]);
			for (int j = 1; j <= price[i][0]; j++)
				scanf("%d", &price[i][j]);
		}
		int x = solve(m, 0);
		if (x < 0)
			printf("no solution\n");
		else
			printf("%d\n", x);
	}
	return 0;
}
