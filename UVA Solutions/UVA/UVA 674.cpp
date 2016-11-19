//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <iterator>
using namespace std;
int coins[] = { 50, 25, 10, 5, 1 };
int counter = 0;
long long dp[6][30010];
int x, y;

long long solve(int indx, int sum) {
	if (indx == 5 || sum < 0) {
		return 0;
	}
	if (sum == 0) {
		return 1;
	}
	if (dp[indx][sum] != -1) {
		return dp[indx][sum];
	}
	if (sum - coins[indx] > -1) {
		return dp[indx][sum] = solve(indx, sum - coins[indx])
				+ solve(indx + 1, sum);
	} else {
		return dp[indx][sum] = solve(indx + 1, sum);
	}
}

int main() {
	int d;
	freopen("input.txt", "r", stdin);
	memset(dp, -1, sizeof(dp));
	while (scanf("%d", &d) != EOF) {
		cout << solve(0, d) << endl;
	}
	return 0;
}
