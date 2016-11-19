//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<vector<pair<int, int> > > city;
int dist[200100];
bool visits[200100];
class comp {
public:
	bool operator()(pair<int, int> n1, pair<int, int> n2) {

		if (n1.second > n2.second)
			return true;
		else
			return false;

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
		visits[u.first] = true;
		v = city[u.first];
		for (int i = 0; i < (int) v.size(); i++) {
			if (!visits[v[i].first] && dist[v[i].first] > v[i].second) {
				dist[v[i].first] = v[i].second;
				q.push(make_pair(v[i].first, v[i].second));
			}
		}
	}
}

int main() {
	long total = 0;
	int x, y, z;
	for (int i = 0; i < 200100; i++) {
		vector<pair<int, int> > temp;
		city.push_back(temp);
	}
	while (true) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) {
			return 0;
		}
		for (int i = 0; i < (n + 10); i++) {
			city[i].clear();
			dist[i] = 999999999;
			visits[i] = false;
		}
		dist[0] = 0;
		total = 0;
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &x, &y, &z);
			total = total + z;
			city[x].push_back(make_pair(y, z));
			city[y].push_back(make_pair(x, z));
		}
		prims();
		for (int i = 0; i < n; i++) {
			total = total - dist[i];
		}
		printf("%ld\n", total);
	}
	return 0;
}
