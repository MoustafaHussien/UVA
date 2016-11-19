#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD n00000007
#define EPS 1e-9
#define  MAX_V 100
#define EQUALE(a, b) (fabs(a - b) < ESP)
using namespace std;
int res[101][101], f, s, t, n;
vector<int> p;
void augment(int v, int minedge) {
	if (v == s) {
		f = minedge;
		return;
	}
	if (p[v] != -1) {
		augment(p[v], min(minedge, res[p[v]][v]));
		res[p[v]][v] -= f, res[v][p[v]] += f;
	}
}
int solve() {
	int mf = 0, u;
	while (1) {
		f = 0, p.assign(101, -1);
		queue<int> q;
		bitset<102> v(0);
		v[s] = 1, q.push(s);
		while (!q.empty()) {
			u = q.front(), q.pop();
			if (u == t)
				break;
			for (int i = 1; i <= n; i++) {
				if (res[u][i] > 0 && !v[i])
					q.push(i), p[i] = u, v[i] = 1;
			}
		}
		augment(t, 99999999);
		if (f == 0)
			return mf;
		mf += f;
	}
	return mf;
}
void debug() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
}
int main(int argc, char **argv) {
//	freopen("in.txt", "r", stdin);
	int e, a, b, c, tc = 1;
	while (1) {
		cin >> n;
		if (n == 0)
			return 0;
		cin >> s >> t >> e;
		memset(res, 0, sizeof(res));
		for (int i = 0; i < e; i++) {
			cin >> a >> b >> c;
			res[a][b] += c, res[b][a] += c;
		}
		int x = solve();
		cout << "Network " << tc << "\nThe bandwidth is " << x << ".\n\n";
		tc++;
	}
	return 0;
}
