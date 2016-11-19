#include<iostream>
#include<sstream>
#include<string.h>
#include<fstream>
#include<vector>
using namespace std;
#define clr(a) memset(a,0,sizeof(a))
bool visit[110000];
vector<vector<long> > graph;
vector<long> sortnode;

void dfs(int node) {
	visit[node] = true;
	vector<long> a;
	a = graph[node];
	for (int j = 0; j < a.size(); j++)
		if (!visit[a[j]])
			dfs(a[j]);
	sortnode.push_back(node);
}

int main() {
	long n, tc, m, x, y, cnt, l;
	for (int i = 0; i < 100100; i++) {
		vector<long> cccc;
		graph.push_back(cccc);
	}
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 0; i < (n + 10); i++) {
			graph[i].clear();
		}
		sortnode.clear();
		for (int i = 1; i <= m; i++) {
			cin >> x >> y;
			graph[x].push_back(y);
		}
		for (int i = 1; i <= n; i++)
			if (!visit[i])
				dfs(i);

		clr(visit);
		l = sortnode.size() - 1;
		cnt = 0;
		for (int i = l; i >= 0; i--)
			if (!visit[sortnode[i]]) {
				cnt++;
				dfs(sortnode[i]);
			}

		cout << cnt << endl;

		sortnode.clear();
		clr(visit);
	}
	return 0;
}
