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
#include <map>
#include <queue>
using namespace std;
int n, m;
string s, t;
map<string, int> x;
vector<vector<pair<int, int> > > city;
int dist[220];
bool visits[220];
int parent[220];
class comp {
public:
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}

};

void prims() {
	priority_queue<pair<int, int>, vector<pair<int, int> >, comp> q;
	q.push(make_pair(x[s], 0));
	dist[x[s]] = 0;
	parent[x[s]] = -1;
	while (!q.empty()) {
		pair<int, int> u;
		u = q.top();
		q.pop();
		visits[u.first] = true;
		if (dist[u.first] != u.second)
			continue;
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
int maximum = 999999;
void dfs(int u) {
	if (parent[u] == -1) {
		return;
	}
	visits[u] = true;
	if (!visits[parent[u]]) {
		maximum = min(maximum, -dist[u]);
		dfs(parent[u]);
	}
}
int main() {
	string a, b;
	int c;
	for (int i = 0; i < 220; i++) {
		vector<pair<int, int> > temp;
		city.push_back(temp);
	}
	int tc = 1;
	while (true) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) {
			printf("\n");
			return 0;
		}
		memset(visits, false, sizeof(visits));
		memset(dist, 127, sizeof(dist));
		x.clear();
		for (int i = 0; i < (n + 10); i++) {
			city[i].clear();
		}
		int j = 1;
		for (int i = 0; i < m; i++) {
			cin >> a;
			cin >> b;
			cin >> c;
			if (x[a] == 0) {
				x[a] = j;
				j++;
			}
			if (x[b] == 0) {
				x[b] = j;
				j++;
			}
			city[x[a]].push_back(make_pair(x[b], -c));
			city[x[b]].push_back(make_pair(x[a], -c));
		}
		cin >> s;
		cin >> t;
		prims();
		memset(visits, false, sizeof(visits));
		maximum = 999999;
		dfs(x[t]);
		if (tc == 1) {
			if (maximum <= 0 || maximum == 999999) {
				printf("Scenario #%d\n0 tons\n", tc, maximum);
			} else
				printf("Scenario #%d\n%d tons\n", tc, maximum);
		} else {
			if (maximum <= 0 || maximum == 999999)
				printf("\nScenario #%d\n0 tons\n", tc, maximum);
			else
				printf("\nScenario #%d\n%d tons\n", tc, maximum);
		}
		tc++;
	}
	return 0;
}
