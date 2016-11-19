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
#include <algorithm>
using namespace std;
int counter = 0;
int dfsnumber[150];
int dfslow[150];
int parent[150];
int n, a, b, c;
vector<vector<int> > network;
vector<pair<int, int> > out;
void solve(int u) {
	dfsnumber[u] = dfslow[u] = counter++;
	vector<int> x = network[u];
	for (int i = 0; i < (int) x.size(); i++) {
		if (dfsnumber[x[i]] == -1) {
			parent[x[i]] = u;
			solve(x[i]);
			if (dfslow[x[i]] > dfsnumber[u]) {
				out.push_back(make_pair(min(u, x[i]), max(u, x[i])));
			}
			dfslow[u] = min(dfslow[u], dfslow[x[i]]);
		} else if (x[i] != parent[u]) {
			dfslow[u] = min(dfslow[u], dfsnumber[x[i]]);
		}
	}
}
bool pairCompare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
	if (a.first < b.first) {
		return true;
	}
	if (a.first == b.first && a.second < b.second) {
		return true;
	}
	return false;
}
void clear() {
	counter = 0;
	out.clear();
	for (int i = 0; i < (n + 2); i++) {
		network[i].clear();
		dfsnumber[i] = -1;
		dfslow[i] = 0;
		parent[i] = 0;
	}
}

int main() {
	for (int i = 0; i < 1000; i++) {
		vector<int> temp;
		network.push_back(temp);
	}
	while (scanf("%d", &n) != EOF) {
		clear();
		for (int i = 0; i < n; i++) {
			scanf("%d (%d)", &a, &b);
			for (int j = 0; j < b; j++) {
				scanf("%d", &c);
				network[a].push_back(c);
			}
		}
		for (int i = 0; i < n; i++) {
			if (dfsnumber[i] == -1) {
				solve(i);
			}
		}

		printf("%d critical links\n", out.size());
		sort(out.begin(), out.end(), pairCompare);
		for (int i = 0; i < out.size(); i++) {
			printf("%d - %d\n", out[i].first, out[i].second);
		}
		printf("\n");
	}
	return 0;
}
