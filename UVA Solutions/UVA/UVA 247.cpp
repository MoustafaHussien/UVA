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
#include <string>
#include <strings.h>
#include <vector>
#include <map>
using namespace std;
vector<vector<int> > graph;
vector<vector<int> > grapht;
map<string, int> t;
map<int, string> tt;
bool visits[30];
int tims[30];
int timer = 1;
bool a7a = true;
void dfs(int x) {
	vector<int> temp = grapht[x];
	if (a7a) {
		cout << tt[x];
		a7a = false;
	} else {
		cout << ", ";
		cout << tt[x];
	}
	for (int i = 0; i < temp.size(); i++) {
		if (!visits[temp[i]]) {
			visits[temp[i]] = true;
			dfs(temp[i]);
		}
	}
}
void calculate_time(int x) {
	vector<int> temp = graph[x];
	for (int i = 0; i < temp.size(); i++) {
		if (!visits[temp[i]]) {
			visits[temp[i]] = true;
			calculate_time(temp[i]);
		}
	}
	tims[timer] = x;
	timer++;
}

int main() {
	int n, m;
	string a, b;
	for (int i = 0; i < 30; i++) {
		vector<int> temp;
		grapht.push_back(temp);
		graph.push_back(temp);
	}
	int test = 1;
	while (true) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) {
			return 0;
		}
		//--------------------------------------
		int z = 1;
		for (int i = 0; i < m; i++) {
			cin >> a;
			cin >> b;
			if (t[a] == 0) {
				t[a] = z;
				tt[z] = a;
				z++;
			}
			if (t[b] == 0) {
				t[b] = z;
				tt[z] = b;
				z++;
			}
			graph[t[a]].push_back(t[b]);
			grapht[t[b]].push_back(t[a]);
		}
		getchar();
		//---------------------------------------
		memset(visits, false, sizeof(visits));
		memset(tims, 0, sizeof(tims));
		timer = 1;
		//---------------------------------------
		for (int i = 1; i <= n; i++) {
			if (!visits[i]) {
				visits[i] = true;
				calculate_time(i);
			}
		}
		//----------------------------------------
		memset(visits, false, sizeof(visits));
		//----------------------------------------
		printf("Calling circles for data set %d:\n", test);
		test++;
		for (int i = n; i > 0; i--) {
			if (!visits[tims[i]]) {
				visits[tims[i]] = true;
				a7a = true;
				dfs(tims[i]);
				printf("\n");
			}
		}
		t.clear();
		tt.clear();
		for (int i = 0; i < 30; i++) {
			graph[i].clear();
			grapht[i].clear();
		}
	}
	return 0;
}
