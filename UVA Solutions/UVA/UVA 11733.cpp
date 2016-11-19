//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int airport, n, m, c;
struct edge {
	int a, b, w;
};
bool comp(edge const& e1, edge const& e2) {
	if (e1.w < e2.w) {
		return true;
	}
	return false;
}
edge x[150000];
int p[20000], r[20000];
int findSet(int i) {
	return (p[i] == i) ? i : (p[i] = findSet(p[i]));
}
bool isSameSet(int i, int j) {
	return findSet(i) == findSet(j);
}
void unionSet(int i, int j) {
	p[findSet(i)] = findSet(j);
}
int main() {
	freopen("input.txt", "r", stdin);
	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%d %d %d", &n, &m, &airport);
		for (int i = 0; i < m; i++) {
			edge e;
			scanf("%d %d %d", &e.a, &e.b, &e.w);
			x[i] = e;
		}
		sort(x, x + m, &comp);
		memset(r, -1, sizeof(r));
		for (int i = 0; i < n + 1; i++) {
			p[i] = i;
		}
		c = n;
		int k, l, ans = 0;
		for (int i = 0; i < m; i++) {
			if (x[i].w < airport) {
				k = findSet(x[i].a);
				l = findSet(x[i].b);
				if (k != l) {
					ans = ans + x[i].w;
					unionSet(l, k);
					c--;
				}
			}
		}
		printf("Case #%d: %d %d\n", t, ans + c * airport, c);
	}
	return 0;
}
