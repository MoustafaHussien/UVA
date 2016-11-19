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
#include <string.h>
#include <stdlib.h>
using namespace std;
int r, c;
int jx, jy, fx, fy;
char maze[1100][1100];
bool visits[1100][1100];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
struct node {
	int x, y, d;
};
queue<node> fire;
void update() {
	int s = fire.size();
	for (int i = 0; i < s; i++) {
		int a = fire.front().x;
		int b = fire.front().y;
		fire.pop();
		node temp;
		for (int i = 0; i < 4; i++) {
			int x = a + dx[i];
			int y = b + dy[i];
			if (x > -1 && x < r && y > -1 && y < c && maze[x][y] != 'F'
					&& maze[x][y] != '#') {
				temp.x = x;
				temp.y = y;
				fire.push(temp);
				maze[x][y] = 'F';
			}
		}
	}
}

void BFS() {
	queue<node> q;
	node temp;
	temp.x = jx;
	temp.y = jy;
	temp.d = 1;
	q.push(temp);
	memset(visits, false, sizeof(visits));
	visits[jx][jy] = true;
	while (!q.empty()) {
		node temp = q.front();
		int x = temp.x;
		int y = temp.y;
		int d = temp.d;
		printf("%d %d %d\n", x, y, d);
		q.pop();
		if (maze[x][y] != 'F') {
			if (x == 0 || x == r - 1 || y == 0 || y == c - 1) {
				printf("%d", d);
				return;
			}
			for (int i = 0; i < 4; i++) {
				if (x + dx[i] > -1 && x + dx[i] < r && y + dy[i] > -1
						&& y + dy[i] < c && maze[x + dx[i]][y + dy[i]] == '.'
						&& !visits[x + dx[i]][y + dy[i]]) {
					visits[x + dx[i]][y + dy[i]] = true;
					node temp;
					temp.x = x + dx[i];
					temp.y = y + dy[i];
					temp.d = d + 1;
					q.push(temp);
				}
			}
		}
		update();
	}
	printf("no way");
	return;
}

int main() {
	scanf("%d %d\n", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			maze[i][j] = getchar();
			if (maze[i][j] == 'J') {
				jx = i;
				jy = j;
			} else if (maze[i][j] == 'F') {
				fx = i;
				fy = j;
			}
		}
		getchar();
	}
	node f;
	f.x = fx;
	f.y = fy;
	fire.push(f);
	BFS();
	return 0;
}
