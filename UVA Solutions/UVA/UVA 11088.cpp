#include <bits/stdc++.h>
using namespace std;
map<int, vector<int> > myMask;
vector<int> t;
int a[16], n, dp[(1 << 15) + 1][600];
void getMask(int k) {
	if (myMask.find(k) != myMask.end())
		return;
	for (int i = 0; i < (1 << k); i++) {
		bitset<15> a(i);
		if (a.count() == 3) {
			myMask[k].push_back(i);
		}
	}
}

bool check(int mask) {
	int c = 0;
	for (int i = 0; i < n; i++) {
		if ((mask >> i & 1) == 1) {
			c += a[i];
		}
	}
	return c >= 20;
}

int solve(int mask, int indx) {
	if (indx == (int) t.size())
		return 0;
	if (dp[mask][indx] != -1) {
		return dp[mask][indx];
	}
	int ret = 0;
	if ((t[indx] & mask) == 0 && check(t[indx]))
		ret = max(ret, solve(t[indx] | mask, indx + 1) + 1);
	ret = max(ret, solve(mask, indx + 1));
	return dp[mask][indx] = ret;
}

int main(int argc, char **argv) {
	freopen("input.txt", "r", stdin);
	int tc = 1;
	while (1) {
		cin >> n;
		if (n == 0)
			return 0;
		getMask(n);
		t = myMask[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		memset(dp, -1, sizeof(dp));
		cout << "Case " << tc << ": " << solve(0, 0) << endl;
		tc++;
	}
}
