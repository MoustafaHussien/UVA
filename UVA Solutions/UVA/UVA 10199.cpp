#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#include <istream>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
int counter = 0;
int dfsnumber[150];
int dfslow[150];
int parent[150];
int rootchildren = 0;
bool points[150];
vector<vector<int> > g;
map<string, int> mt;
map<int, string> m;
int n, r;
int dfsRoot;
void solve(int u) {
	dfsnumber[u] = dfslow[u] = counter++;
	vector<int> x = g[u];
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

void clera() {
	rootchildren = 0;
	counter = 0;
	m.clear();
	mt.clear();
	for (int i = 0; i < (n + 2); i++) {
		g[i].clear();
		dfsnumber[i] = -1;
		dfslow[i] = 0;
		parent[i] = 0;
		points[i] = false;
	}
}

int main(int argc, char **argv) {
	string a, b;
	int tc = 1;
	for (int i = 0; i < 150; i++) {
		vector<int> temp;
		g.push_back(temp);
	}
	while (true) {
		scanf("%d", &n);
		if (n == 0) {
			return 0;
		}
		clera();
		for (int i = 0; i < n; i++) {
			cin >> a;
			m[i] = a;
			mt[a] = i;
		}
		scanf("%d", &r);
		for (int i = 0; i < r; i++) {
			cin >> a;
			cin >> b;
			g[mt[a]].push_back(mt[b]);
			g[mt[b]].push_back(mt[a]);
		}
		for (int i = 0; i < n; i++) {
			if (dfsnumber[i] == -1) {
				dfsRoot = i;
				rootchildren = 0;
				solve(i);
				points[dfsRoot] = (rootchildren > 1);
			}
		}
		int y = 0;
		string yy[150];
		for (int i = 0; i < n; i++) {
			if (points[i]) {
				yy[y] = m[i];
				y++;
			}
		}
		sort(yy, yy + y);

		if (tc > 1) {
			printf("\n");
		}
		printf("City map #%d: %d camera(s) found\n", tc, y);
		for (int i = 0; i < y; i++) {
			cout << yy[i] << endl;
		}
		tc++;
	}
}
