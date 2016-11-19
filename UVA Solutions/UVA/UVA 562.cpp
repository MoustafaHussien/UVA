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
#include <cmath>
#include <math.h>
using namespace std;
int tc, m, coins[110];
unsigned short dp[50001][101];
int solve(int a, int indx) {
	if (indx >= m) {
		return a;
	}
	if (dp[a][indx] != 51400) {
		return dp[a][indx];
	}
	return dp[a][indx] = min(solve(abs(a + coins[indx]), indx + 1),
			solve(abs(a - coins[indx]), indx + 1));
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d", &coins[i]);
		}
		memset(dp, 200, sizeof(dp));
		//cout << dp[0][0] << endl;
		cout << solve(0, 0) << endl;
	}
	return 0;
}
