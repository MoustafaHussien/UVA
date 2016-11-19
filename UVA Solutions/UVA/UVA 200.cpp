#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 100000007
#define EpS 1e-9
#define ll	long long
#define MAX_V 52
#define INF 1073741824
#define EQUALE(a, b) (fabs(a - b) < ESp)
using namespace std;
vector<vector<int> > g;
vector<string> a;
vector<int> ts;
bool v[26], used[26];
void buildGraph() {
	g.resize(26);
	for (int i = 1; i < (int) a.size(); i++)
		for (int j = 0; j < (int) min(a[i].size(), a[i - 1].size()); j++)
			if (a[i - 1][j] != a[i][j]) {
				g[a[i - 1][j] - 'A'].push_back(a[i][j] - 'A');
				used[a[i - 1][j] - 'A'] = used[a[i][j] - 'A'] = 1;
				break;

			}
}
void dfs(int i) {
	v[i] = 1;
	for (int j = 0; j < (int) g[i].size(); j++) {
		if (!v[g[i][j]])
			dfs(g[i][j]);
	}
	ts.push_back(i);
}
void solve() {
	char a;
	memset(used, false, sizeof(used)), memset(v, false, sizeof(v));
	buildGraph();
	for (int i = 0; i < 26; i++)
		if (!v[i] && used[i])
			dfs(i);
	for (int i = ts.size() - 1; i > -1; i--)
		a = 'A' + ts[i], cout << a;
	cout << endl;
}
int main(int argc, char **argv) {
	string s;
	while (1) {
		cin >> s;
		if (s[0] == '#') {
			solve();
			return 0;
		}
		a.push_back(s);
	}
	return 0;
}
