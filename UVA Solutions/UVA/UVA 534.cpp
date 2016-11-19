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
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
int n;
pair<int, int> rocks[210];
double dist[30000];
bool visits[30000];
int parent[30000];

class CompareDist {
public:
	bool operator()(pair<int, double> n1, pair<int, double> n2) {

		if (n1.second > n2.second) {
			return true;
		}
		return false;
	}
};

double calc_dist(int a, int b) {
	double temp;
	temp = sqrt(
			pow((rocks[a].first - rocks[b].first), 2)
					+ pow((rocks[a].second - rocks[b].second), 2));
	return temp;
}

void prims() {
	priority_queue<pair<int, double>, vector<pair<int, double> >, CompareDist> pq;
	pq.push(make_pair(0, 0));
	double d;
	while (!pq.empty()) {
		pair<int, double> u = pq.top();
		pq.pop();
		if (u.second != dist[u.first])
			continue;
		visits[u.first] = true;
		for (int i = 0; i < n; i++) {
			if ((i != u.first) && (visits[i] == false)) {
				d = calc_dist(i, u.first);
				if (d < dist[i]) {
					dist[i] = d;
					parent[i] = u.first;
					pq.push(make_pair(i, d));
				}
			}
		}
	}
}

int main() {
	int x, y;
	int er = 1;
	while (true) {
		scanf("%d", &n);
		if (n == 0) {
			return 0;
		}
		memset(dist, 127, sizeof(dist));
		memset(visits, false, sizeof(visits));
		memset(parent, -1, sizeof(parent));
		dist[0] = 0;
		parent[0] = -1;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			rocks[i] = make_pair(x, y);
		}
		getchar();
		prims();
		int i = 1;
		double xxx = -1;
		while (parent[i] != -1) {
			xxx = max(xxx, dist[i]);
			i = parent[i];
		}
		printf("Scenario #%d\n", er);
		printf("Frog Distance = %0.3lf\n\n", xxx);
		er++;
	}
	return 0;
}
