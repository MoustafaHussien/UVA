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
#include <vector>
#include <string.h>
using namespace std;
int tc, n, m, t;
int a, b, c;
int weight[1010];
vector<vector<pair<int, int> > > space;
int main() {
	scanf("%d", &tc);
	for (int i = 0; i < 1010; i++) {
		vector<pair<int, int> > temp;
		space.push_back(temp);
	}

	while (tc--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < (n + 2); i++) {
			space[i].clear();
		}
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			space[a].push_back(make_pair(b, c));
		}
		memset(weight, 127, sizeof(weight));
		weight[0] = 0;
		bool bb = true;
		for (int i = 0; i < n; i++) {
			vector<pair<int, int> > e;
			e = space[i];
			for (int j = 0; j < e.size(); j++) {
				if (weight[i] + e[j].second < weight[e[j].first]) {
					weight[e[j].first] = weight[i] + e[j].second;
					bb = false;
				}
			}
			if (bb) {
				break;
			}
		}
		bool go = true;
		for (int i = 0; i < n - 1 && go; i++) {
			vector<pair<int, int> > e;
			e = space[i];
			for (int j = 0; j < e.size() && go; j++) {
				if (weight[i] + e[j].second < weight[e[j].first]) {
					go = false;
					break;
				}
			}
		}
		if (go) {
			printf("not possible\n");
		} else {
			printf("possible\n");
		}
	}
	return 0;
}
