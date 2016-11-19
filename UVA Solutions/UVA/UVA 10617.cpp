//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;
char a[100];
long long dp[110][110];
long long solve(int i, int j) {
	if (i >= j) {
		return 1;
	} else if (j - i == 1) {
		return 2 + (a[i] == a[j]);
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	long long ans = 0;
	if (a[i] == a[j]) {
		ans = solve(i + 1, j - 1) + 1;
	}
	ans += solve(i + 1, j) + solve(i, j - 1) - solve(i + 1, j - 1);
	return dp[i][j] = ans;
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> a;
		memset(dp, -1, sizeof dp);
		cout << solve(0, strlen(a) - 1) << endl;
	}
	return 0;
}
