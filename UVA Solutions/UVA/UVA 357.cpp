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
int coins[] = { 1, 10, 5, 25, 50 };
long long dp[5][30010];
long long solve(int indx, int remain) {
	if (indx == 5 || remain < 0) {
		return 0;
	}
	if (dp[indx][remain] != -1) {
		return dp[indx][remain];
	}
	if (remain == 0) {
		return 1;
	}
	return dp[indx][remain] = solve(indx, remain - coins[indx])
			+ solve(indx + 1, remain);
}
int main() {
	int input;
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	memset(dp, -1, sizeof(dp));
	long long temp;
	while (scanf("%d", &input) != EOF) {
		temp = solve(0, input);
		if (temp == 1) {
			printf("There is only 1 way to produce %d cents change.\n", input);
		} else {
			printf("There are %lld ways to produce %d cents change.\n", temp,
					input);
		}
	}
	return 0;
}
