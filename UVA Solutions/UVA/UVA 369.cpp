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
long long dp[110][110];
long long solve(int n, int k) {
	if (k == 0) {
		return 1;
	}
	if (k == 1 || n - k == 1) {
		return n;
	}
	if (dp[n][k] != -1) {
		return dp[n][k];
	}
	dp[n][k] = solve(n - 1, k - 1) + solve(n - 1, k);
	//cout << dp[n][k] << endl;
	return dp[n][k];
}
int main() {
	int n, k;
	freopen("input.txt", "r", stdin);
	while (true) {
		memset(dp, -1, sizeof dp);
		cin >> n >> k;
		if (n == k && n == 0) {
			return 0;
		}
		if (n == k) {
			cout << n << " things taken " << k << " at a time is " << "1"
					<< " exactly." << endl;
		} else {
			cout << n << " things taken " << k << " at a time is "
					<< solve(n, k) << " exactly." << endl;
		}
	}
	return 0;
}
