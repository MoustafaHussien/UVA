//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bitset>
#include <string.h>
#define modulo 1000000007
using namespace std;
int n, m, tc, target;
int dp[101][11][1024];
int solve(int i, int pre, int mask) {
	if (i == m && mask == target) {
		return 1;
	}
	if (i == m) {
		return 0;
	}
	if (dp[i][pre][mask] != -1) {
		return dp[i][pre][mask];
	}
	int ans = 0;
	if (mask == target) {
		ans += 1;
		ans = ans % modulo;
	}
	if (pre > 0) {
		int b = mask;
		b |= 1 << (pre - 1);
		ans += solve(i + 1, pre - 1, b);
		ans = ans % modulo;
	}
	if (pre < n - 1) {
		int b = mask;
		b |= 1 << (pre + 1);
		ans += solve(i + 1, pre + 1, b);
		ans = ans % modulo;
	}
	return dp[i][pre][mask] = ans % modulo;

}
int main() {
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		if (m < n) {
			cout << 0 << endl;
			continue;
		}
		target = 1 << n;
		target--;
		int ans = 0;
		memset(dp, -1, sizeof dp);
		for (int i = 1; i < n; i++) {
			int b = 1 << i;
			ans += solve(1, i, b);
			ans = ans % modulo;
		}
		cout << ans << endl;
	}
	return 0;
}
