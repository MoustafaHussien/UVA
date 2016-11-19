//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <tuple>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <string>
#define oo 999999999
using namespace std;
int n, m;
int grid[1000][1000];

struct node {
	int x, y, weight;
	int visited = 0;
	node() {
	}
	node(int X, int Y, int Weight) {
		x = X;
		y = Y;
		weight = Weight;
	}
	bool operator <(node X) const {
		return weight > X.weight;
	}
};

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void dijkstra() {
	priority_queue<node> q;
	q.push(node(0, 0, grid[0][0]));
	node temp;
	int r, c;
	int min_cost[1000][1000];
	memset(min_cost, -1, sizeof(min_cost));
	min_cost[0][0] = grid[0][0];
	while (true) {
		temp = q.top();
		q.pop();
		if (temp.visited == 0) {
			temp.visited = 1;
			if (temp.x == n - 1 && temp.y == m - 1) {
				printf("%d\n", temp.weight);
				break;
			}
			for (int i = 0; i < 4; i++) {
				r = temp.x + dx[i];
				c = temp.y + dy[i];
				if (r >= 0 && r < n && c >= 0 && c < m
						&& (min_cost[r][c] == -1
								|| (min_cost[r][c]
										> min_cost[temp.x][temp.y] + grid[r][c]))) {
					min_cost[r][c] = min_cost[temp.x][temp.y] + grid[r][c];
					q.push(node(r, c, min_cost[r][c]));
				}
			}
		}
	}
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		scanf("%d", &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &grid[i][j]);
			}
		}
		dijkstra();
	}
}
