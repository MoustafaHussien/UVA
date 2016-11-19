//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char s[1001];
int dp[1001][1001];
int solve(int i, int j) {
	if (j <= i) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	if (s[i] == s[j]) {
		return dp[i][j] = solve(i + 1, j - 1);
	}
	return dp[i][j] = 1
			+ min(min(solve(i + 1, j), solve(i, j - 1)), solve(i + 1, j - 1));

}
int main() {
	freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> s;
		memset(dp, -1, sizeof dp);
		cout << "Case " << i << ": " << solve(0, strlen(s) - 1) << endl;
	}
}
