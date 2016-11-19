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
#include <cstring>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
int n;
int counter = 0;
int dfsnumber[150];
int dfslow[150];
int parent[150];
int rootchildren = 0;
bool points[150];
vector<vector<int> > network;

void solve(int u) {
	dfsnumber[u] = dfslow[u] = counter++;
	vector<int> x = network[u];
	for (int i = 0; i < (int) x.size(); i++) {
		if (dfsnumber[x[i]] == -1) {
			parent[x[i]] = u;
			if (u == 1) {
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

void clear() {
	rootchildren = 0;
	counter = 0;
	for (int i = 0; i < (n + 2); i++) {
		network[i].clear();
		dfsnumber[i] = -1;
		dfslow[i] = 0;
		parent[i] = 0;
		points[i] = false;
	}
}

int main() {
	for (int i = 0; i < 105; i++) {
		vector<int> temp;
		network.push_back(temp);
	}
	char input[10000], target;
	while (scanf("%d", &n) && n) {
		getchar();
		clear();
		while (gets(input) && strcmp(input, "0")) {
			char *pch;
			pch = strtok(input, " ");
			target = atoi(pch);
			pch = strtok(NULL, " ");
			while (pch != NULL) {
				network[target].push_back(atoi(pch));
				network[atoi(pch)].push_back(target);
				pch = strtok(NULL, " ");
			}
		}
		rootchildren = 0;
		solve(1);
		points[1] = (rootchildren > 1);
		int count = 0;
		for (int i = 0; i <= n; i++) {
			if (points[i]) {
				count++;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
