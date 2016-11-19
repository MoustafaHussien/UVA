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
#include <math.h>
#include <stdlib.h>
#define MAX 4294967296;
using namespace std;
long long a[6000], length;
long long dp[6000][2000];

long long solve(int n, int k) {
	if (k == 0)
		return 0;
	else if (length == n || length - 1 == n || k * 3 > length - n) {
		return MAX;
	} else if (dp[n][k] != -1) {
		return dp[n][k];

	}
	return dp[n][k] = min(solve(n + 1, k),
			solve(n + 2, k - 1) + (a[n] - a[n + 1]) * (a[n] - a[n + 1]));
}
int main() {
	freopen("input.txt", "r", stdin);
	long long tc, k;
	cin >> tc;
	for (long long i = 0; i < tc; i++) {
		cin >> k;
		cin >> length;
		for (long long i = 0; i < length; i++) {
			cin >> a[i];
		}
		k = k + 8;
		memset(dp, -1, sizeof dp);
		cout << solve(0, k) << endl;
	}
	return 0;
}
