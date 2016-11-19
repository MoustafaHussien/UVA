#include <bits/stdc++.h>
using namespace std;
vector<string> a, b;
int n, m;
string ans;
short dp[3010][3010];
short solve(int i, int j) {
	if (i == n || j == m) {
		return 0;
	}
	if (dp[i][j] != -1)
		return dp[i][j];
	if (a[i] == b[j]) {
		return dp[i][j] = (solve(i + 1, j + 1) + 1);
	} else {
		return dp[i][j] = max(solve(i + 1, j), solve(i, j + 1));
	}
}
void build(int i, int j) {
	if (i == n || j == m) {
		return;
	}
	if (a[i] == b[j]) {
		ans += a[i]+" ";
		build(i + 1, j + 1);
	} else if (dp[i + 1][j] > dp[i][j + 1])
		build(i + 1, j);
	else
		build(i, j + 1);

}

int main(int argc, char **argv) {
	freopen("input.txt", "r", stdin);
	string temp;
	while (cin >> temp) {
		memset(dp, -1, sizeof(dp));
		a.clear();
		b.clear();
		ans.clear();
		a.push_back(temp);
		while (cin >> temp && temp != "#")
			a.push_back(temp);
		while (cin >> temp && temp != "#")
			b.push_back(temp);
		n = a.size();
		m = b.size();
		ans = "";
		solve(0, 0);
		build(0, 0);
		for (int i = 0; i < (int) ans.size() - 1; i++)
			cout << ans[i];
		cout << endl;
	}
	return 0;
}
