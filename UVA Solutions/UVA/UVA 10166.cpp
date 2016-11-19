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
#include <map>
#include <vector>
#include <queue>
using namespace std;

map<string, int> m;
int wakeuptime;
int startcity;
int endcity;
int c, t, ti;
int times[102];
int parent[102];
struct edge {
	int destination;
	int starttime;
	int arrivaltime;
};

class Compare {
public:
	bool operator()(pair<int, int> n1, pair<int, int> n2) {

		if (n1.second > n2.second)
			return true;
		else
			return false;

	}
};

vector<vector<edge> > graph;
void Dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int> >, Compare> q;
	q.push(make_pair(1, wakeuptime));
	while (!q.empty()) {
		pair<int, int> temp = q.top();
		q.pop();
		vector<edge> x = graph[temp.first];
		for (int i = 0; i < x.size(); i++) {
			if (x[i].starttime >= temp.second
					&& times[x[i].destination] > x[i].arrivaltime) {
				times[x[i].destination] = x[i].arrivaltime;
				parent[x[i].destination] = temp.first;
				q.push(make_pair(x[i].destination, x[i].arrivaltime));
			}
		}
	}
}
int main() {

	for (int i = 0; i < 102; i++) {
		vector<edge> fill;
		graph.push_back(fill);
	}
	while (cin >> c) {
		if (c == 0) {
			return 0;
		}
		m.clear();
		string city;
		for (int i = 1; i <= c; i++) {
			cin >> city;
			m[city] = i;
		}
		cin >> t;
		int a;
		string b;
		vector<pair<int, int> > justarray;
		for (int i = 0; i < t; i++) {
			cin >> ti;
			for (int j = 0; j < ti; j++) {
				cin >> a >> b;
				pair<int, int> v;
				v.first = m[b];
				v.second = a;
				justarray.push_back(v);
			}
			for (int k = 0; k + 1 < ti; k++) {
				pair<int, int> previous = justarray[k];
				pair<int, int> current = justarray[k + 1];
				edge temp;
				temp.destination = current.first;
				temp.arrivaltime = current.second;
				temp.starttime = previous.second;
				graph[previous.first].push_back(temp);

			}
		}
		cin >> wakeuptime;
		cin >> b;
		startcity = m[b];
		cin >> b;
		endcity = m[b];
		memset(times, 9999999, sizeof(times));
		memset(parent, 0, sizeof(times));
		times[startcity] = wakeuptime;
		Dijkstra();
		if (parent[endcity] == 0) {
			printf("not connected\n");
		} else {
			printf("%d\n", times[endcity]);
		}
	}
	return 0;
}

