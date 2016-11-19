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
char a[10010], b[110];
long long dp[101][10001];
int n, m;

int solve(int i, int j) {
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	int ans = 0;
	if (i == n) {
		ans = 1;
	} else if (j == m) {
		ans = 0;
	} else {
		ans = solve(i, j + 1);
		if (b[i] == a[j]) {
			ans += solve(i + 1, j + 1);
		}
	}
	return dp[i][j] = ans;
}

int main() {
	// solution is right but we need big integer
	freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		cin >> a;
		cin >> b;
		n = strlen(b);
		m = strlen(a);
		memset(dp, -1, sizeof dp);
		cout << solve(0, 0) << endl;
	}
	return 0;
}

