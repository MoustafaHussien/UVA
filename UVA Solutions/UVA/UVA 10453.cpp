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
#include <vector>
using namespace std;
char a[1010], result[20010];
long long ptr = 0;
long long dp[1010][1010];
string ans;

long long solve(long long i, long long j) {
	if (i > j) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	long long x;
	x = 1 << 30;
	if (a[i] == a[j]) {
		x = solve(i + 1, j - 1);
	}
	return dp[i][j] = min(min(solve(i + 1, j) + 1, solve(i, j - 1) + 1), x);
}

void create_result(long long i, long long j) {
	if (i > j)
		return;
	if (i == j) {
		result[ptr++] = a[j];
		return;
	} else if (a[i] == a[j]) {
		result[ptr++] = a[i];
		create_result(i + 1, j - 1);
		result[ptr++] = a[j];
	} else if (dp[i][j - 1] <= dp[i + 1][j]) {
		result[ptr++] = a[j];
		create_result(i, j - 1);
		result[ptr++] = a[j];
	} else {
		result[ptr++] = a[i];
		create_result(i + 1, j);
		result[ptr++] = a[i];
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	while (gets(a)) {
		if (strlen(a) == 0) {
			cout << "0\n";
		} else {
			ptr = 0;
			memset(dp, -1, sizeof dp);
			printf("%lld", solve(0, strlen(a) - 1));
			create_result(0, strlen(a) - 1);
			result[ptr] = 0;
			printf(" %s\n", result);
		}
	}
}
