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
#include <queue>
#include <vector>
using namespace std;
int n, s, t, c;
int mf, f;
struct edge {
	int to, from, cpacity, flow;
};
bool visits[110];
edge* parent[110];
vector<vector<edge*> > network;
void bfs() {
	queue<int> q;
	memset(visits, false, sizeof(visits));
	q.push(s);
	edge*e;
	int u;
	visits[s] = true;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (int i = 0; i < (int) network[u].size(); i++) {
			e = network[u][i];
			if (e->from == u && e->cpacity != 0 && !visits[e->to]) {
				q.push(e->to), parent[e->to] = e;
				visits[e->to] = true;
			}
			if (e->to == u && e->flow != 0 && !visits[e->from]) {
				q.push(e->from), parent[e->from] = e;
				visits[e->from] = true;
			}
		}
	}

}

void backtrack(int node, int minc) {
	if (node == s) {
		f = minc;
		return;
	} else {
		if (parent[node]->to == node) {
			backtrack(parent[node]->from, min(parent[node]->cpacity, minc));
			parent[node]->cpacity = parent[node]->cpacity - f;
			parent[node]->flow = parent[node]->flow + f;
		} else {
			backtrack(parent[node]->to, min(parent[node]->flow, minc));
			parent[node]->cpacity = parent[node]->cpacity + f;
			parent[node]->flow = parent[node]->flow - f;
		}
	}
}

int main() {
	int x, y, z;
	for (int i = 0; i < 110; i++) {
		vector<edge*> temp;
		network.push_back(temp);
	}
	int tc = 1;
	while (true) {
		scanf("%d", &n);
		if (n == 0) {
			return 0;
		}
		for (int i = 0; i < 105; i++) {
			network[i].clear();
		}
		memset(visits, false, sizeof(visits));
		scanf("%d %d %d", &s, &t, &c);
		s--, t--;
		for (int i = 0; i < c; i++) {
			scanf("%d %d %d", &x, &y, &z);
			edge* e = new edge();
			edge* r = new edge();
			x--, y--, e->from = x, e->to = y;
			e->cpacity = z, e->flow = 0, r->from = y;
			r->to = x, r->cpacity = z, r->flow = 0;
			network[x].push_back(e), network[x].push_back(r);
			network[y].push_back(e), network[y].push_back(r);
		}
		mf = 0;
		bfs();
		while (visits[t]) {
			backtrack(t, 9999999);
			mf = mf + f;
			bfs();
		}
		printf("Network %d\n", tc);
		printf("The bandwidth is %d.\n\n", mf);
		tc++;
	}

	return 0;
}
