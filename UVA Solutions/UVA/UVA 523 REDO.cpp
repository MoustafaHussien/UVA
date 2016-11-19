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
#include <stdlib.h>
#include <string.h>
using namespace std;
struct node {
	int x, y, z, distance;
};
char maze[40][40][40];
bool visits[40][40][40];
int l, r, c, x, y, z;
int dx[] = { -1, 1, 0, 0, 0, 0 }; //level
int dy[] = { 0, 0, -1, 1, 0, 0 }; //row
int dz[] = { 0, 0, 0, 0, -1, 1 }; //column
void BFS() {
	queue<node> q;
	node start;
	start.x = x;
	start.y = y;
	start.z = z;
	start.distance = 0;
	q.push(start);
	memset(visits, false, sizeof(visits));
	visits[start.x][start.y][start.z] = true;
	while (!q.empty()) {
		node h;
		h = q.front();
		q.pop();
		if (maze[h.x][h.y][h.z] == 'E') {
			printf("Escaped in %d minute(s).\n", h.distance);
			return;
		}
		int f, g, v;
		for (int i = 0; i < 6; i++) {
			f = dx[i] + h.x;
			g = dy[i] + h.y;
			v = dz[i] + h.z;
			if (f > -1 && f < l && g > -1 && g < r && v > -1 && v < c
					&& !visits[f][g][v] && maze[f][g][v] != '#') {
				node temp;
				temp.x = f;
				temp.y = g;
				temp.z = v;
				temp.distance = h.distance + 1;
				q.push(temp);
				visits[f][g][v] = true;
			}
		}
	}
	printf("Trapped!\n");
	return;
}

int main() {
//scan and clear
	while (scanf("%d%d%d", &l, &r, &c) && l && r && c) {
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> maze[i][j][k];
					if (maze[i][j][k] == 'S') {
						x = i;
						y = j;
						z = k;
					}
				}
				getchar();
			}
		}
		BFS();
	}
	return 0;
}
