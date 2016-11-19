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
#include <string.h>
#include <queue>
#include <map>
#include <algorithm>
#include<sstream>
using namespace std;
#define oo 2^30
int f, i, tc;
map<int, int> firestations;
vector<vector<pair<int, int> > > graph;
int dist[520];
int dist2[520];
class CompareDist {
public:
	bool operator()(pair<int, int> n1, pair<int, int> n2) {

		if (n1.second < n2.second)
			return true;
		else
			return false;

	}
};
int location = 1;
int maxdistance = -1;
void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int> >, CompareDist> pq;
	for (int j = 1; j <= i; j++) {
		if (firestations[j] == 1) {
			pq.push(make_pair(j, 0));
		}
	}
	while (!pq.empty()) {
		pair<int, int> u;
		u = pq.top();
		pq.pop();
		if (u.second != dist[u.first])
			continue;
		vector<pair<int, int> > temp;
		temp = graph[u.first];
		for (int j = 0; j < temp.size(); j++) {
			int alt = dist[u.first] + temp[j].second;
			if (alt < dist[temp[j].first]) {
				dist[temp[j].first] = alt;
				pq.push(make_pair(temp[j].first, alt));
			}
		}
	}
}

void dijkstra_2(int node) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, CompareDist> pq;
	pq.push(make_pair(node, 0));
	while (!pq.empty()) {
		pair<int, int> u;
		u = pq.top();
		pq.pop();
		if (u.second != dist2[u.first])
			continue;
		vector<pair<int, int> > temp;
		temp = graph[u.first];
		for (int j = 0; j < temp.size(); j++) {
			int alt = dist2[u.first] + temp[j].second;
			if (alt < dist2[temp[j].first]) {
				dist2[temp[j].first] = alt;
				pq.push(make_pair(temp[j].first, alt));
			}
		}
	}

}

int main() {
	for (int j = 0; j < 510; j++) {
		vector<pair<int, int> > temp;
		graph.push_back(temp);
	}

	int a, b, cost;
	scanf("%d", &tc);
	while (tc--) {
		if (tc != 1) {
			printf("\n");
		}
		cin >> f >> i;
		//------------------------------------------
		memset(dist, oo, sizeof(dist));
		firestations.clear();
		for (int j = 0; j < 510; j++) {
			graph[i].clear();
		}
		location = 1;
		maxdistance = -1;
		//-------------------------------------------
		for (int j = 0; j < f; j++) {
			cin >> a;
			firestations[a] = 1;
			dist[a] = 0;
		}
		//--------fuck start from here--------------------------------
		string s;
		while (1) {
			getline(cin, s);
			istringstream is(s);
			if (s.empty())
				break;
			is >> a >> b >> cost;
			graph[a].push_back(make_pair(b, cost));
			graph[b].push_back(make_pair(a, cost));
		}

		//--------fuck end here---------------------------------------
		dijkstra();

		for (int j = 1; j <= i; j++) {
			if (dist[j] > maxdistance) {
				maxdistance = dist[j];
			}
		}

		for (int j = 1; j <= i; j++) {
			if (firestations[j] == 0) {
				memcpy((void*) dist2, (void*) dist, 503 * sizeof(int));
				dist2[j] = 0;
				dijkstra_2(j);
				int mx = -1;
				for (int k = 1; k <= i; k++) {
					if (mx < dist2[k])
						mx = dist2[k];
				}
				if (mx < maxdistance) {
					maxdistance = mx;
					location = j;
				}
			}
		}

		printf("%d\n", location);
	}
	return 0;
}

