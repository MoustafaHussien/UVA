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
#include <string.h>
#include <queue>
#include <map>
#include <math.h>
#include <cmath>
using namespace std;
int n;
struct node {
	double x, y, d;
	int number;
	bool v;
};
node grid[110];
class CompareDist {
public:
	bool operator()(pair<int, double> n1, pair<int, double> n2) {

		if (n1.second > n2.second)
			return true;
		else
			return false;

	}
};

double calc_dis(int a, int b) {
	double temp;
	temp = sqrt(
			pow((grid[a].x - grid[b].x), 2) + pow((grid[a].y - grid[b].y), 2));
	return temp;
}

void prims() {
	priority_queue<pair<int, int>, vector<pair<int, double> >, CompareDist> q;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		pair<int, double> temp = q.top();
		grid[temp.first].v = true;
		q.pop();
		for (int i = 0; i < n; i++) {
			if (i != temp.first && (grid[i].v == false)
					&& calc_dis(i, temp.first) < grid[i].d) {
				grid[i].d = calc_dis(i, temp.first);
				q.push(make_pair(i, grid[i].d));
			}
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	getchar();
	while (tc--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lf %lf", &grid[i].x, &grid[i].y);
			grid[i].d = pow(2, 31);
			grid[i].v = false;
			grid[i].number = i;
		}
		grid[0].d = 0;
		prims();
		double count = 0;
		for (int i = 0; i < n; i++) {
			count = count + grid[i].d;
		}
		printf("%0.2lf\n", count);
		if (tc > 0) {
			printf("\n");
		}
	}
}
