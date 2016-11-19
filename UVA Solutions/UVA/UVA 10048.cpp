//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
vector<vector<pair<int, int> > > city;
vector<vector<pair<int, int> > > mst;
bool visits[105];
int dist[105];
int ans[105];
int parent[105];
int c, s, q;
class comp {
public:
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

void prims(int node) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, comp> q;
	dist[node] = 0;
	parent[node] = -1;
	q.push(make_pair(node, 0));
	while (!q.empty()) {
		pair<int, int> u;
		u = q.top();
		q.pop();
		if (dist[u.first] != u.second) {
			continue;
		}
		visits[u.first] = true;
		vector<pair<int, int> > v;
		v = city[u.first];
		for (int i = 0; i < (int) v.size(); i++) {
			if (!visits[v[i].first] && dist[v[i].first] > v[i].second) {
				dist[v[i].first] = v[i].second;
				parent[v[i].first] = u.first;
				q.push(make_pair(v[i].first, v[i].second));
			}
		}
	}
}

void fill() {
	for (int i = 0; i < 105; i++) {
		vector<pair<int, int> > temp;
		city.push_back(temp);
		vector<pair<int, int> > x;
		mst.push_back(x);
	}
}
void dfs(int u, int t) {
	if (u == t) {
		return;
	}
	for (int i = 0; i < (int) mst[u].size(); i++) {
		if (ans[mst[u][i].first] == -1) {
			ans[mst[u][i].first] = max(ans[u], mst[u][i].second);
			dfs(mst[u][i].first, t);
		}
	}
}
int main() {
	int a, b, d;
	int tc = 1;
	fill();
	while (true) {
		scanf("%d %d %d", &c, &s, &q);
		if (c == 0 && s == 0 && q == 0) {
			return 0;
		}
		for (int i = 0; i <= c; i++) {
			city[i].clear();
			mst[i].clear();
		}
		memset(visits, false, sizeof(visits));
		memset(dist, 127, sizeof(dist));
		memset(parent, -1, sizeof(parent));
		for (int i = 0; i < s; i++) {
			scanf("%d %d %d", &a, &b, &d);
			a--;
			b--;
			city[a].push_back(make_pair(b, d));
			city[b].push_back(make_pair(a, d));
		}
		for (int i = 0; i < c; i++) {
			if (!visits[i]) {
				prims(i);
			}
		}
		for (int i = 0; i < c; i++) {
			if (parent[i] != -1) {
				mst[i].push_back(make_pair(parent[i], dist[i]));
				mst[parent[i]].push_back(make_pair(i, dist[i]));
			}
		}
		if (tc == 1) {
			printf("Case #1\n");
		} else {
			printf("\nCase #%d\n", tc);
		}
		tc++;
		for (int i = 0; i < q; i++) {
			scanf("%d %d", &a, &b);
			a--;
			b--;
			memset(ans, -1, sizeof(ans));
			ans[a] = 0;
			dfs(a, b);
			if (ans[b] == -1) {
				printf("no path\n");
			} else {
				printf("%d\n", ans[b]);
			}
		}
	}
	return 0;
}
