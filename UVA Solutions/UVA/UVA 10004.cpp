//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <stdlib.h>
#include <string.h>
using namespace std;
int n, m;
vector<vector<int> > graph;
int visits[300];

bool BFS() {
	queue<int> q;
	q.push(0);
	visits[0] = 1;
	int temp;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		vector<int> x = graph[temp];
		for (int i = 0; i < x.size(); i++) {
			if (visits[x[i]] == visits[temp]) {
				return false;
			}
			if (visits[x[i]] == 0) {
				if (visits[temp] == 1) {
					visits[x[i]] = 2;
				} else {
					visits[x[i]] = 1;
				}
				q.push(x[i]);
			}
		}
	}
	return true;
}

int main() {
	for (int i = 0; i < 210; i++) {
		vector<int> t;
		graph.push_back(t);
	}
	while (true) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		scanf("%d", &m);
		memset(visits, 0, sizeof(visits));
		for (int i = 0; i < graph.size(); i++) {
			graph[i].clear();
		}
		int x, y;
		for (int j = 0; j < m; j++) {
			scanf("%d %d", &x, &y);
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		getchar();
		if (BFS()) {
			printf("BICOLORABLE.\n");
		} else {
			printf("NOT BICOLORABLE.\n");
		}
	}
	return 0;
}
