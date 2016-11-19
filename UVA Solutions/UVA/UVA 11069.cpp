#include <bits/stdc++.h>
using namespace std;
int n;
map<pair<int, int>, int> dp;
map<pair<int, int>, bool> mark;
int solve(int cur, int pre) {
	if (cur == n) {
		return 1;
	}
	if (mark[make_pair(cur, pre)] == true) {
		return dp[make_pair(cur, pre)];
	}
	int dist = cur - pre, ans = 0;
	if (dist == 1) {
		ans += solve(cur + 1, pre);
	}
	if (dist == 2) {
		ans += solve(cur + 1, pre); //leaveit
		ans += solve(cur + 1, cur); //takeit
	}
	if (dist == 3) {
		ans += solve(cur + 1, cur); //takeit
	}
	mark[make_pair(cur, pre)] = true;
	return dp[make_pair(cur, pre)] = ans;
}
int main(int argc, char **argv) {
	while (scanf("%d", &n) != EOF) {
		cout << solve(0, -1) << endl;
		mark.clear(), dp.clear();
	}
}

