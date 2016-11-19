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
int dp[1010][1010];
char a[1010];
int solve(int i, int j) {
	if (i == j) {
		return 1;
	}
	if (i > j) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	int ans = -99999999;
	if (a[i] == a[j]) {
		ans = solve(i + 1, j - 1) + 2;
	} else {
		ans = max(ans, max(solve(i + 1, j), solve(i, j - 1)));
	}
	return dp[i][j] = ans;
}
int main() {
	int tc;
	freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	getc(stdin);

	while (tc--) {
		gets(a);
		if (strlen(a) == 0) {
			printf("0\n");
			continue;
		}
		memset(dp, -1, sizeof(dp));
		int ans = solve(0, strlen(a) - 1);
		printf("%d\n", ans);
	}

	return 0;
}
