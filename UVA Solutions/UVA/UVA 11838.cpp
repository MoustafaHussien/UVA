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
using namespace std;
vector<vector<int> > city;
vector<vector<int> > cityt;
bool visits[2100];
int times[2100];
int timer = 1;

void DFS(int node) {
	vector<int> temp = cityt[node];
	for (int i = 0; i < temp.size(); i++) {
		if (!visits[temp[i]]) {
			visits[temp[i]] = true;
			DFS(temp[i]);
		}
	}
}

void calculate_time(int x) {
	vector<int> temp = city[x];
	for (int i = 0; i < temp.size(); i++) {
		if (!visits[temp[i]]) {
			visits[temp[i]] = true;
			calculate_time(temp[i]);
		}
	}
	times[timer] = x;
	timer++;
}

int main() {
	int n, m;
	int a, b, c;
	vector<int> temp;
	for (int i = 0; i < 2100; i++) {
		city.push_back(temp);
		cityt.push_back(temp);
	}
	while (true) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) {
			return 0;
		}
		//-----------------------------------
		memset(visits, false, sizeof(visits));
		memset(times, 0, sizeof(times));
		timer = 1;
		for (int i = 0; i < n + 2; i++) {
			city[i].clear();
			cityt[i].clear();
		}
		//-----------------------------------
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			if (c == 1) {
				city[a].push_back(b);
				cityt[b].push_back(a);
			} else if (c == 2) {
				city[a].push_back(b);
				city[b].push_back(a);
				cityt[a].push_back(b);
				cityt[b].push_back(a);
			}
		}
		//-----------------------------------
		for (int i = 1; i <= n; i++) {
			if (!visits[i]) {
				visits[i] = true;
				calculate_time(i);
			}
		}
		//-----------------------------------
		memset(visits, false, sizeof(visits));
		//------------------------------------
		DFS(times[n]);
		bool one = true;
		for (int i = 1; i <= n; i++) {
			if (!visits[i]) {
				printf("0\n");
				one = false;
				break;
			}
		}
		if (one) {
			printf("1\n");
		}
	}
	return 0;
}
