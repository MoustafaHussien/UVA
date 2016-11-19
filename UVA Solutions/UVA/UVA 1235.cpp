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
struct key {
	int d;
	int pattern[4];
	int number;
	bool v;
	int a7a;
};
key lock[510];
class CompareDist {
public:
	bool operator()(pair<int, int> n1, pair<int, int> n2) {

		if (n1.second > n2.second)
			return true;
		else
			return false;

	}
};

int calc_dis(int a, int b) {
	int d = 0;
	int c;
	for (int i = 0; i < 4; i++) {
		c = abs(lock[a].pattern[i] - lock[b].pattern[i]);
		if (c > 5) {
			d = d + 10 - c;
		} else {
			d = d + c;
		}
	}
	return d;
}

void generate(int temp, int i) {
	int a, b, c, d;
	a = temp % 10;
	b = temp % 100;
	c = temp % 1000;
	d = temp % 10000;
	key x;
	x.pattern[0] = a;
	x.pattern[1] = b / 10;
	x.pattern[2] = c / 100;
	x.pattern[3] = d / 1000;
	x.v = false;
	x.number = i;
	x.d = (int) pow(2, 30);
	lock[i] = x;
}

void prims(int index) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, CompareDist> q;
	q.push(make_pair(index, lock[index].d));
	int z;
	while (!q.empty()) {
		pair<int, int> temp = q.top();
		lock[temp.first].v = true;
		q.pop();
		for (int i = 0; i <= n; i++) {
			if (i != temp.first && (lock[i].v == false)) {
				z = calc_dis(i, temp.first);
				if (z <= lock[i].d) {
					lock[i].d = z;
					q.push(make_pair(i, lock[i].d));
				}
			}
		}
	}
}

int main() {
	int tc, temp;
	//----------------------------------------
	key start;
	start.d = 0;
	start.number = 0;
	start.v = false;
	start.pattern[0] = 0;
	start.pattern[1] = 0;
	start.pattern[2] = 0;
	start.pattern[3] = 0;
	lock[0] = start;
	//----------------------------------------
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &temp);
			generate(temp, i);
			lock[i].a7a = calc_dis(0, i);
		}
		lock[0].v = true;
		int max = (int) pow(2, 30);
		int r;
		for (int i = 1; i <= n; i++) {
			if (lock[i].a7a < max) {
				max = lock[i].a7a;
				r = i;
			}
		}
		prims(r);
		int count = 0;
		for (int i = 0; i <= n; i++) {
			if (lock[i].d != 1073741824) {
				count = count + lock[i].d;
			}
		}
		count = count + max;
		printf("%d\n", count);
	}
}
