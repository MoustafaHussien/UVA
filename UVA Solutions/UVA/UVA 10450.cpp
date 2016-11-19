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
int n, tc;
long long dp[2][60];
long long solve(int last, int indx) {
	if (indx == n) {
		return 1;
	}
	if (dp[last][indx] != -1) {
		return dp[last][indx];
	}
	long long ans = 0;
	ans += solve(0, indx + 1);
	if (last == 0) {
		ans += solve(1, indx + 1);
	}
	return dp[last][indx] = ans;
}
int main() {
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		memset(dp, -1, sizeof dp);
		cin >> n;
		cout << "Scenario #" << i << ":" << endl;
		cout << solve(0, 0) << "\n" << endl;
	}
	return 0;
}
