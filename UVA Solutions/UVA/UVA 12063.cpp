#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int n, k;
long long dp[65][34][101];
long long solve(int i, int r, long long mod) {
	if (r == 0) {
		if (mod == 0)
			return 1;
		return 0;
	}
	if (i == -1) {
		return 0;
	}
	if (dp[i][r][mod] != -1) {
		return dp[i][r][mod];
	}
	long long ans = 0;
	ans += solve(i - 1, r, mod);
	long long x = 1;
	x <<= i;
	x %= k;
	ans += solve(i - 1, r - 1, (mod + x) % k);
	return dp[i][r][mod] = ans;
}

int main(int argc, char **argv) {
//	freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		memset(dp, -1, sizeof dp);
		unsigned long long ans = 0;
		cin >> n;
		cin >> k;
		if (n % 2 != 0 || k == 0) {
			ans = 0;
		} else {
			unsigned long long x = 1;
			x <<= n - 1;
			x %= k;
			ans = solve(n - 2, (n / 2) - 1, x);
		}
		cout << "Case " << i << ": " << ans << endl;
	}
	return 0;
}
