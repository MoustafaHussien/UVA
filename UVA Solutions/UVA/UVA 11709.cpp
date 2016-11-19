#include <iostream>
#include <string.h>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <stdio.h>
#define N  1010
using namespace std;
vector<int> edges[N];
vector<int> rEdges[N];
bool vis[N];
vector<int> sortedNode;

void reset() {
	for (int i = 0; i < N; i++) {
		edges[i].clear();
		rEdges[i].clear();
	}
	sortedNode.clear();
	memset(vis, false, sizeof(vis));
}

void dfs1(int x) {
	vis[x] = true;
	for (int u = 0; u < (int) edges[x].size(); u++)
		if (!vis[edges[x][u]])
			dfs1(edges[x][u]);

	sortedNode.push_back(x);
}

void dfs2(int x) {
	vis[x] = false;
	for (int u = 0; u < (int) rEdges[x].size(); u++)
		if (vis[rEdges[x][u]])
			dfs2(rEdges[x][u]);
}

int main(int argc, char** argv) {
	int p, t;
	while (scanf("%d %d", &p, &t)) {
		if (p == 0 && t == 0)
			break;
		getchar();
		reset();
		char name[100];
		map<string, int> name_index;

		for (int i = 0; i < p; i++) {
			gets(name);
			name_index[name] = i;
		}
		char name1[100];
		char name2[100];
		for (int i = 0; i < t; i++) {
			gets(name1);
			gets(name2);
			edges[name_index[name1]].push_back(name_index[name2]);
			rEdges[name_index[name2]].push_back(name_index[name1]);
		}

		for (int i = 0; i < p; i++) {
			if (!vis[i])
				dfs1(i);
		}

		int c = 0;
		for (int i = sortedNode.size() - 1; i >= 0; i--) {
			if (vis[sortedNode[i]]) {
				dfs2(sortedNode[i]);
				c++;
			}
		}
		printf("%d\n", c);

	}

	return 0;
}
