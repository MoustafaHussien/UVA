#include <bits/stdc++.h>
using namespace std;
string a, b;
int n, m;
string ans;
short dp[1000][1000];
short solve(int i, int j) {
	if (i == n) {
		return m - j;
	}
	if (j == m) {
		return n - i;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	if (a[i] == b[j]) {
		return dp[i][j] = solve(i + 1, j + 1);
	} else {
		dp[i][j] = min(solve(i + 1, j), solve(i, j + 1)) + 1;
		return dp[i][j] = min((int) dp[i][j], solve(i + 1, j + 1) + 1);
	}
}

int main(int argc, char **argv) {
	freopen("input.txt", "r", stdin);
	while (cin >> n) {
		memset(dp, -1, sizeof(dp));
		cin >> a;
		cin >> m;
		cin >> b;
		cout << solve(0, 0) << endl;
	}
	return 0;
}
