#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007
#define ZERO 1e-9
using namespace std;
int dp[301][301];
string a, b;
int solve(int i, int j) {
	if (i == (int) a.size() || j == (int) b.size() || a[i] != b[j])
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	return dp[i][j] = 1 + solve(i + 1, j + 1);
}
string ans = "";
void build(int i, int j) {
	if (i == (int) a.size() || j == (int) b.size() || a[i] != b[j])
		return;
	ans += a[i];
	return build(i + 1, j + 1);
}
void process() {
	memset(dp, -1, sizeof(dp));
	int len = -1;
	set<string> s;
	for (int i = 0; i < (int) a.size(); i++)
		for (int j = 0; j < (int) b.size(); j++)
			len = max(len, solve(i, j));
	for (int i = 0; i < (int) a.size(); i++)
		for (int j = 0; j < (int) b.size(); j++)
			if (solve(i, j) == len && len > 0) {
				build(i, j);
				s.insert(ans);
				ans = "";
			}
	if (s.size() == 0) {
		cout << "No common sequence.\n";
		return;
	}
	if (len != 0)
		for (set<string>::iterator it = s.begin(); it != s.end(); it++)
			cout << *it << endl;
}
int main(int argc, char **argv) {
	freopen("input.txt", "r", stdin);
	char x;
	bool line = false;
	while (1) {
		getline(cin, a);
		getline(cin, b);
		if (line)
			cout << endl;
		line = 1;
		process();
		if (scanf("%c", &x) == EOF)
			return 0;
	}
	return 0;
}
