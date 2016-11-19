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
#include <queue>
using namespace std;
vector<vector<int> > edges;
bool visited[10010];
int answer;
void BFS(int x) {
	if (visited[x])
		return;
	queue<int> q;
	visited[x] = true;
	q.push(x);
	answer++;
	int y, i;
	vector<int> e;
	while (!q.empty()) {
		y = q.front();
		q.pop();
		e = edges[y];
		for (i = 0; i < e.size(); i++) {
			if (!visited[e[i]]) {
				visited[e[i]] = true;
				answer++;
				q.push(e[i]);
			}
		}
	}
}

int main() {
	for (int i = 0; i < 10010; i++) {
		vector<int> t;
		edges.push_back(t);
	}
	int tc, n, m, l, x, y;
	scanf("%d", &tc);
	while (tc-- != 0) {
		scanf("%d%d%d", &n, &m, &l);
		for (int i = 1; i <= n; i++)
			edges[i].clear();
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &x, &y);
			edges[x].push_back(y);
		}
		for (int i = 1; i <= n; i++)
			visited[i] = false;
		answer = 0;
		for (int i = 0; i < l; i++) {
			scanf("%d", &x);
			BFS(x);
		}
		printf("%d\n", answer);
	}
	return 0;
}
