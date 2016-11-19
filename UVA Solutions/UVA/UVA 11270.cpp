#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007
#define ZERO 1e-9
using namespace std;
int n, m; //n for rows m for colums
vector<vector<int> > newmask;
long long dp[(1 << 10) + 1][101];
void getmask(int oldmask, int ind, int mask) {
	if (ind == m) {
		newmask[oldmask].push_back(mask);
		return;
	}
	if (((oldmask >> ind) & 1) == 1) //cant put one here
		getmask(oldmask, ind + 1, mask);
	if (((oldmask >> ind) & 1) == 0) //one here
		getmask(oldmask, ind + 1, (mask | 1 << ind));
	if (ind < m - 1 && ((oldmask >> ind) & 1) == 0
			&& ((oldmask >> (ind + 1)) & 1) == 0)
		getmask(oldmask, ind + 2, (mask));
}

long long solve(int r, int mask) {
	if (r == n && mask == 0)
		return 1;
	if (r == n)
		return 0;
	if (dp[mask][r] != -1)
		return dp[mask][r];
	if (newmask[mask].size() == 0) {
		getmask(mask, 0, 0);
	}
	long long ans = 0;
	for (int i = 0; i < (int) newmask[mask].size(); i++)
		ans += solve(r + 1, newmask[mask][i]);
	return dp[mask][r] = ans;
}

int main(int argc, char **argv) {
	freopen("input.txt", "r", stdin);
	while (scanf("%d %d", &n, &m) == 2) {
		int a = n, b = m;
		m = min(a, b), n = max(a, b);
		if (n % 2 != 0 && m % 2 != 0) {
			cout << "0\n";
		} else {
			newmask.clear();
			for (int i = 0; i <= (1 << m); i++) {
				vector<int> x;
				newmask.push_back(x);
			}
			memset(dp, -1, sizeof(dp));
			cout << solve(0, 0) << endl;
		}
	}
	return 0;
}
