#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 100000007
#define EpS 1e-10
#define ll	long long
#define MAX_V 52
#define INF 1073741824
#define EQUALE(a, b) (fabs(a - b) < EpS)
using namespace std;
vector<unordered_map<int, pair<int, double> > > adj;
int n, m, s, t, f;
vector<int> p;
vector<double> dist;
void augment(int v, int e) {
	if (v == s) {
		f = e;
		return;
	} else if (p[v] != -1) {
		augment(p[v], min(e, adj[p[v]][v].F));
		adj[p[v]][v].F -= f, adj[v][p[v]].F += f;
	}
}
void build() {
	double a;
	adj.clear(), adj.resize(2 + n + m), s = 0, t = n + m + 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a;
			adj[j][m + i] = make_pair(1, a);
			adj[m + i][j] = make_pair(0, -1 * a);
		}
	}
	for (int i = 1; i <= m; i++)
		adj[0][i] = make_pair(1, 0), adj[i][0] = make_pair(0, 0);
	for (int i = m + 1; i <= n + m; i++)
		adj[i][t] = make_pair(1, 0), adj[t][i] = make_pair(0, 0);
}
void solve() {
	double mf = 0, mc = 0;
	unordered_map<int, pair<int, double> >::iterator i;
	pair<int, double> u;
	while (1) {
		priority_queue<pair<int, double>, vector<pair<int, double> >,
				greater<pair<int, double> > > q;
		f = 0, q.push(mp(0, 0.0));
		dist.assign(n + m + 2, INF), dist[0] = 0.0, p.assign(n + m + 2, -1);
		while (!q.empty()) {
			u = q.top(), q.pop();
			if (u.F == t)
				break;
			if (EQUALE(dist[u.F], u.S))
				for (i = adj[u.F].begin(); i != adj[u.F].end(); i++)
					if (i->S.F > 0 && dist[i->F] > EpS + dist[u.F] + i->S.S) {
						dist[i->F] = dist[u.F] + i->S.S, p[i->F] = u.F;
						q.push(mp(i->F, dist[i->F]));
					}
		}
		augment(t, INF);
		if (f == 0 || EQUALE(INF, dist[t]))
			break;
		mf += f * 1.0, mc += dist[t] * f * 1.0;
	}
	double ans = mc * 1.0 / mf * 1.0;
	ans += EpS, printf("%0.2f\n", ans);
}
int main(int argc, char **argv) {
	freopen("in.txt", "r", stdin);
	while (1) {
		cin >> n >> m;
		if (n + m == 0)
			return 0;
		build(), solve();
	}
	return 0;
}
