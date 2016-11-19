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
#include <stdlib.h>
#include <queue>
#include <string.h>
using namespace std;
vector<vector<int> > graph;
int visits[210];
int v, e;
int solve(int n) {
	queue<int> q;
	q.push(n);
	visits[n] = 1;
	int ones = 1;
	int twos = 0;
	while (!q.empty()) {
		vector<int> x = graph[q.front()];
		int y = q.front();
		q.pop();
		for (int i = 0; i < x.size(); i++) {
			if (visits[x[i]] == visits[y]) {
				return -1;
			} else if (visits[x[i]] == 0 && visits[y] == 1) {
				visits[x[i]] = 2;
				q.push(x[i]);
				twos++;
			} else if (visits[x[i]] == 0 && visits[y] == 2) {
				visits[x[i]] = 1;
				q.push(x[i]);
				ones++;
			}
		}
	}
	if (twos == 0 && ones == 1) {
		return 1;
	}
	return min(ones, twos);
}
int main() {
	int t, x, y;
	for (int i = 0; i < 210; i++) {
		vector<int> temp;
		graph.push_back(temp);
	}
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < 210; i++) {
			graph[i].clear();
		}
		memset(visits, 0, sizeof(visits));
		scanf("%d %d", &v, &e);
		if (e == 0) {
			printf("%d\n", v);
		} else {
			for (int i = 0; i < e; i++) {
				scanf("%d %d", &x, &y);
				graph[x].push_back(y);
				graph[y].push_back(x);
			}
			bool go = true;
			int ans = 0;
			for (int i = 0; i < v && go; i++) {
				if (visits[i] == 0) {
					int x = solve(i);
					if (x == -1) {
						printf("-1\n");
						go = false;
					} else {
						ans = ans + x;
					}
				}
			}
			if (go) {
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}
