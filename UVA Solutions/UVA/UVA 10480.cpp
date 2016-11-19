#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD n00000007
#define EpS 1e-9
#define MAX_V 52
#define INF 1073741824
#define EQUALE(a, b) (fabs(a - b) < ESp)
using namespace std;
int res[MAX_V][MAX_V], f, s, t, n, m;
int vis[MAX_V];
vector<int> p;
void augment(int v, int minEdge) {
	if (v == s) {
		f = minEdge;
		return;
	} else if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f, res[v][p[v]] += f;
	}
}
void solve() {
	while (1) {
		bitset<MAX_V> dist(0);
		queue<int> q;
		dist[s] = 0, f = 0, q.push(s), p.assign(n + 1, -1);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t)
				break;
			for (int v = 1; v <= n; v++)
				if (res[u][v] > 0 && dist[v] == 0)
					dist[v] = 1, q.push(v), p[v] = u;
		}
		augment(t, INF);
		if (f == 0)
			break;
	}
}
void bfs(int ss, int x) {
	queue<int> q;
	vis[ss] = x, q.push(ss), p.assign(n + 1, -1);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v = 1; v <= n; v++)
			if (res[u][v] > 0 && vis[v] != x)
				vis[v] = x, q.push(v), p[v] = u;
	}
}
int main(int argc, char **argv) {
	freopen("in.txt", "r", stdin);
	s = 1, t = 2;
	int a, b, c;
	while (1) {
		cin >> n >> m;
		if (n + m == 0)
			return 0;
		memset(res, 0, sizeof(res)), memset(vis, 0, sizeof(vis));
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			res[a][b] = c, res[b][a] = c;
		}
		solve();
		bfs(1, 1), bfs(1, 2);
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (vis[i] != vis[j] && (res[i][j] + res[j][i] != 0))
					cout << i << " " << j << endl;

		cout << endl;
	}
	return 0;
}
