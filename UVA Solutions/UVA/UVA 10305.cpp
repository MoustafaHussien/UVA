//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int n, m;
bool graph[110][110];
int result[110];
bool visits[110];
int t;

void DFS(int x) {
	for (int i = 1; i <= n; i++) {
		if (graph[x][i] && !visits[i]) {
			visits[i] = true;
			DFS(i);
		}
	}
	result[t++] = x;
}

int main() {
	int i, j;
	while (true) {
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0) {
			return 0;
		}
		memset(graph, false, sizeof(graph));
		memset(visits, false, sizeof(visits));
		t = 0;
		for (int k = 0; k < m; k++) {
			scanf("%d%d", &i, &j);
			graph[i][j] = true;
		}
		for (int i = 1; i <= n; i++) {
			if (!visits[i]) {
				visits[i] = true;
				DFS(i);
			}
		}
		for (int i = t - 1; i >= 0; i--) {
			printf("%d ", result[i]);
		}
		printf("\n");
	}
	return 0;
}
