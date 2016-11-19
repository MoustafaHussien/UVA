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
#include <vector>
#include <map>
#include <queue>
using namespace std;
int r, d, s;
vector<vector<int> > rooms;
vector<vector<int> > lights;
map<pair<int, int>, int> m;
queue<pair<int, int> > q;
void build(pair<int, int>) {

}
void BFS(pair<int, int> state) {
	q.push(state);
	m[state] = 1;
	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
	}
}
int main() {
	int x, y;
	while (true) {
		scanf("%d %d %d", &r, &d, &s);
		if (r == 0 && s == 0 && d == 0) {
			return 0;
		}
		for (int i = 0; i < d; i++) {
			scanf("%d %d", &x, &y);
			rooms[x].push_back(y);
			rooms[y].push_back(x);
		}
		for (int i = 0; i < s; i++) {
			scanf("%d %d", &x, &y);
			lights[x].push_back(y);
		}
		pair<int, int> start;
		start.first = 1;
		start.second = 1;
		m[start] = 1;
		BFS(start);
	}
	return 0;
}
