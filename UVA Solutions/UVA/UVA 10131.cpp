//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
using namespace std;
vector<pair<int, int> > e;
map<pair<int, int>, int> m;
int lis[10000];
int parent[10000];
bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second > b.second) {
		return true;
	} else if (a.second == b.second) {
		return (a.first < b.first);
	}
	return false;
}
int main() {
	int w, q, t = 1;
	//freopen("input.txt", "r", stdin);
	while (scanf("%d %d", &w, &q) != EOF) {
		e.push_back(make_pair(w, q));
		m[make_pair(w, q)] = t;
		t++;
	}
	sort(e.begin(), e.end(), comp);
	memset(lis, -1, sizeof(lis));
	memset(parent, -1, sizeof(parent));
	lis[0] = 1;
	int maxi = 0;
	int start = 0;
	for (int i = 1; i < (int) e.size(); i++) {
		int maxx = 0;
		for (int j = 0; j < i; j++) {
			if (e[i].first > e[j].first && e[i].second < e[j].second) {
				if (maxx < lis[j])
					parent[i] = j;
				maxx = max(maxx, lis[j]);
			}
		}
		lis[i] = 1 + maxx;
		if (lis[i] >= maxi) {
			maxi = lis[i];
			start = i;
		}
	}
	int i = start;
	vector<int> ans;
	while (i != -1) {
		ans.push_back(m[e[i]]);
		i = parent[i];
	}
	printf("%d\n", ans.size());
	for (int i = ans.size() - 1; i > -1; i--) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
