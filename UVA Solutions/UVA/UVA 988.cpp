#include <bits/stdc++.h>
using namespace std;
int n, dp[20000];
vector<vector<int>> v;
int solve(int u) {
	if (u == n)
		return 0;
	if (dp[u] != -1)
		return dp[u];
	long long ans = 0;
	for (int i = 0; i < (int) v[u].size(); i++) {
		ans += solve(v[u][i]);
	}
	return dp[u] = ans;
}

int main(int argc, char **argv) {
	freopen("input.txt", "r", stdin);
	int a, b;
	bool print = false;
	while (scanf("%d", &n) != EOF) {
		memset(dp, -1, sizeof(dp));
		v.clear();
		for (int i = 0; i < n; i++) {
			vector<int> x;
			v.push_back(x);
			cin >> a;
			for (int j = 0; j < a; j++) {
				cin >> b;
				v[i].push_back(b);
			}
			if (a == 0)
				dp[i] = 1;
		}
		if (print) {
			cout << endl;
		}
		print = true;
		cout << solve(0) << endl;
	}
	return 0;
}
