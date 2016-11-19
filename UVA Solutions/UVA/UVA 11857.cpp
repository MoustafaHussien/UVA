//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<vector<pair<int, int> > > city;
int dist[1000100];
int visits[1000100];

class comp {
public:
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

void prims() {
	priority_queue<pair<int, int>, vector<pair<int, int> >, comp> q;
	q.push(make_pair(0, 0));
	dist[0] = 0;
	while (!q.empty()) {
		pair<int, int> u;
		u = q.top();
		q.pop();
		vector<pair<int, int> > v;
		v = city[u.first];
		visits[u.first] = true;
		if (dist[u.first] != u.second)
			continue;
		for (int i = 0; i < (int) v.size(); i++) {
			if (!visits[v[i].first] && dist[v[i].first] > v[i].second) {
				dist[v[i].first] = v[i].second;
				q.push(make_pair(v[i].first, v[i].second));
			}
		}
	}
}
int main() {
	int a, b, c;
	for (int i = 0; i < 1000100; i++) {
		vector<pair<int, int> > temp;
		city.push_back(temp);
	}
	while (true) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)
			return 0;
		memset(visits, false, sizeof(visits));
		memset(dist, 127, sizeof(dist));
		dist[0] = 0;
		for (int i = 0; i < (n + 10); i++) {
			city[i].clear();
		}
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			city[a].push_back(make_pair(b, c));
			city[b].push_back(make_pair(a, c));
		}
		prims();
		int ans = -1;
		bool go = true;
		for (int i = 0; i < n; i++) {
			if (!visits[i]) {
				printf("IMPOSSIBLE\n");
				go = false;
				break;
			}
			ans = max(ans, dist[i]);
		}
		if (go) {
			printf("%d\n", ans);
		}
	}
	return 0;
}
