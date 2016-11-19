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
int coins[21];
void setup() {
	coins[0] = 1, coins[1] = 8, coins[2] = 27, coins[3] = 64, coins[4] = 125, coins[5] =
			216, coins[6] = 343, coins[7] = 512, coins[8] = 729, coins[9] =
			1000, coins[10] = 1331, coins[11] = 1728, coins[12] = 2197, coins[13] =
			2744, coins[14] = 3375, coins[15] = 4096, coins[16] = 4913, coins[17] =
			5832, coins[18] = 6859, coins[19] = 8000, coins[20] = 9261;
}
long long dp[21][10010];
long long solve(int indx, int remain) {
	if (indx > 20 || remain < 0) {
		return 0;
	}
	if (remain == 0) {
		return 1;
	}
	if (dp[indx][remain] != -1) {
		return dp[indx][remain];
	}
	long long ans = 0;
	if (remain >= coins[indx]) {
		ans = solve(indx, remain - coins[indx]);
	}
	ans += solve(indx + 1, remain);
	return dp[indx][remain] = ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	setup();
	int coin;
	while (cin >> coin) {
		memset(dp, -1, sizeof dp);
		cout << solve(0, coin) << endl;
	}
	return 0;
}
