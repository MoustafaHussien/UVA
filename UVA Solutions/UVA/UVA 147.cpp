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
int coins[] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };
int counter = 0;
long long dp[12][30010];
int x, y;

long long solve(int indx, int sum) {
	//printf("%d %d\n", indx, sum);
	if (indx == 11 || sum < 0) {
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
	double a, c;
	int d;
	freopen("input.txt", "r", stdin);
	memset(dp, -1, sizeof(dp));
	while (true) {
		scanf("%lf", &a);
		if (a <= 0) {
			return 0;
		}
		c = a * 100;
		d = round(c);
		long long b = solve(0, d);
		printf("%6.2lf%17lld\n", a, b);
	}
	return 0;
}
