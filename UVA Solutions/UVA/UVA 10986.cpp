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
int n, m, s, t, a, b, c, node, weight, alt;
int dist[50010];
vector<vector<pair<int, int> > > edges;
class CompareDist {
public:
	bool operator()(pair<int, int> n1, pair<int, int> n2) {
		if (n1.second > n2.second)
			return true;
		else
			return false;
	}
};
bool found = false;
void dijksta() {
	priority_queue<pair<int, int>, vector<pair<int, int> >, CompareDist> pq;
	dist[s] = 0;
	pq.push(make_pair(s, 0));
	while (!pq.empty()) {
		pair<int, int> u;
		u = pq.top();
		pq.pop();
		if (u.first == t) {
			found = true;
			return;
		}
		vector<pair<int, int> > v;
		v = edges[u.first];
		for (int i = 0; i < (int) v.size(); i++) {
			alt = u.second + v[i].second;
			if (alt < dist[v[i].first]) {
				dist[v[i].first] = alt;
				pq.push(make_pair(v[i].first, alt));
			}
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < 50010; i++) {
		vector<pair<int, int> > temp;
		edges.push_back(temp);
	}
	///-------start here
	for (int x = 1; x <= tc; x++) {
		scanf("%d %d %d %d", &n, &m, &s, &t);
		for (int i = 0; i < (n + 2); i++) {
			edges[i].clear();
		}
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			edges[a].push_back(make_pair(b, c));
			edges[b].push_back(make_pair(a, c));
		}
		memset(dist, 999999, sizeof(int) * (m + 2));
		dijksta();
		printf("Case #%d: ", x);
		if (found) {
			printf("%d\n", dist[t]);
			found = false;
		} else {
			printf("unreachable\n");
		}
	}
	return 0;
}
