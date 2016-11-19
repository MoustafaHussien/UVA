//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
#include <math.h>
#include <cmath>
using namespace std;
long counter = 0;
long dfsnumber[150100];
long dfslow[150100];
long parent[150100];
long rootchildren = 0;
bool points[150100];
bool visits[150100];
vector<vector<long> > g;
long n;
long dfsRoot;
void solve(int u) {
	dfsnumber[u] = dfslow[u] = counter++;
	vector<long> x = g[u];
	for (int i = 0; i < (int) x.size(); i++) {
		if (dfsnumber[x[i]] == -1) {
			parent[x[i]] = u;
			if (u == dfsRoot) {
				rootchildren++;
			}
			solve(x[i]);
			if (dfslow[x[i]] >= dfsnumber[u]) {
				points[u] = true;
			}
			dfslow[u] = min(dfslow[u], dfslow[x[i]]);
		} else if (x[i] != parent[u]) {
			dfslow[u] = min(dfslow[u], dfsnumber[x[i]]);
		}
	}
}

long dfs(int node) {
	long counter = 1;
	vector<long> x = g[node];
	visits[node] = true;
	for (int i = 0; i < (long) x.size(); i++) {
		if (!visits[x[i]] && !points[x[i]]) {
			counter += dfs(x[i]);
		}
	}
	return counter;
}

void clear() {
	rootchildren = 0;
	counter = 0;
	for (int i = 0; i < 150100; i++) {
		g[i].clear();
		dfsnumber[i] = -1;
		dfslow[i] = 0;
		parent[i] = 0;
		points[i] = false;
		visits[i] = false;
	}
}

int main() {
	for (int i = 0; i < 150100; i++) {
		vector<long> x;
		g.push_back(x);
	}
	long t = 1;
	while (true) {
		scanf("%ld", &n);
		if (n == 0) {
			return 0;
		}
		clear();
		int a, b;
		int r = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &a, &b);
			r = max(max(a, b), r);
			g[a].push_back(b);
			g[b].push_back(a);
		}
		for (int i = 1; i <= r; i++) {
			if (dfsnumber[i] == -1) {
				dfsRoot = i;
				rootchildren = 0;
				solve(i);
				points[dfsRoot] = (rootchildren > 1);
			}
		}
		long minishaft = 0;
		long ways = 1;
		int atrcoun = 0;
		for (int i = 1; i <= r; i++) {
			if (points[i]) {
				atrcoun++;
			}
		}
		for (int i = 1; i <= r; i++) {
			if (!visits[i] && !points[i]) {
				minishaft++;
				ways = ways * dfs(i);
			}
		}
		for (int i = 1; i <= r; i++) {
			if (points[i]) {
				printf(">>%d ", i);
			}
		}
		printf("Case %ld: %ld %ld\n", t, minishaft, ways);
		t++;
	}
	return 0;
}
