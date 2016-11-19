//============================================================================
// name        : UVa.cpp
// author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;
const int MX = 1007;
long long n, m, a[MX];
long long dp[MX][MX]; //indx len
long long solve(int i, int j) {
	if (i == 0 && j == 0) {
		return 1;
	}
	if (j == 0) {
		return 1;
	}
	if (i == 0) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	return dp[i][j] = (solve(i - 1, j - 1) * a[i] + solve(i - 1, j)) % m;

}
int main() {
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) {
			return 0;
		}
		memset(dp, -1, sizeof dp);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = max(ans, solve(n, i));
		}
		cout << ans << endl;
	}
}
