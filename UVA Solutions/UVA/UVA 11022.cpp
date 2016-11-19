#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define SZ size
using namespace std;
string s;
int fact(int l, int r) {
	string a = s.substr(l, r - l + 1);
	for (int i = 1; i <= (int) a.size(); i++)
		if (a.size() % i == 0) {
			string b = "";
			for (int j = 0; j < (int) a.size() / i; j++)
				b += a.substr(0, i);
			if (b.compare(a) == 0 && i != (int) a.size())
				return i;
		}
	return -1;
}
int dp[81][81];
int solve(int l, int r) {
//	cout << l << " " << r << endl;
	if (l == r)
		return 1;
	if (dp[l][r] != -1) {
		return dp[l][r];
	}
	int ret = 99999999, x = fact(l, r);
//	cout << s.substr(l, r - l + 1) << " " << x << endl;
	if (x != -1) //this can full factorized
		ret = solve(l, x + l - 1);
	for (int i = l; i < r; i++) {
		ret = min(ret, solve(l, i) + solve(i + 1, r));
	}
	return dp[l][r] = ret;
}
int main(int argc, char **argv) {
//	freopen("in.txt", "r", stdin);
	while (1) {
		getline(cin, s);
		if (s[0] == '*')
			break;
		memset(dp, -1, sizeof(dp));
		cout << solve(0, s.size() - 1) << endl;
	}
	return 0;
}
