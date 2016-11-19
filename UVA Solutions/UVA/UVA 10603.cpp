#include <utility>
#include <string>
#include <tuple>
#include <map>
#include <queue>
#include <stdio.h>
#include <math.h>
#include <cmath>
using namespace std;
int d;
int weights[3];
map<tuple<int, int, int>, int> dist;
class CompareDist {
public:
	bool operator()(pair<tuple<int, int, int>, int> n1,
			pair<tuple<int, int, int>, int> n2) {

		if (n1.second > n2.second)
			return true;
		else
			return false;

	}
};
bool found_d = false;
int movedwater;
int closedd = -1;
int minimumwater = (int) pow(2, 30);
pair<tuple<int, int, int>, int> move(pair<tuple<int, int, int>, int> u,
		int from, int to) {
	int w[] = { get<0>(u.first), get<1>(u.first), get<2>(u.first) };
	int copyofw[] = { get<0>(u.first), get<1>(u.first), get<2>(u.first) };
	w[to] = w[to] + w[from];
	w[from] = 0;
	if (w[to] > weights[to]) {
		w[from] = w[to] - weights[to];
		w[to] = weights[to];
	}
	pair<tuple<int, int, int>, int> n;
	n.second = u.second + copyofw[from] - w[from];
	n.first = make_tuple(w[0], w[1], w[2]);
	return n;
}

void dijkstra() {
	priority_queue<pair<tuple<int, int, int>, int>,
			vector<pair<tuple<int, int, int>, int> >, CompareDist> pq;
	pq.push(make_pair(make_tuple(0, 0, weights[2]), 0));
	dist[make_tuple(0, 0, weights[2])] = 0;
	while (!pq.empty()) {
		pair<tuple<int, int, int>, int> u;
		u = pq.top();
		int w[] = { get<0>(u.first), get<1>(u.first), get<2>(u.first) };
		pq.pop();
		if (u.second == dist[u.first]) {
			if (w[0] == d || w[1] == d || w[2] == d) {
				found_d = true;
				movedwater = u.second;
				return;
			}
			for (int i = 0; i < 3; i++) {
				if ((w[i] > closedd && w[i] < d)
						|| (w[i] == d && u.second < minimumwater)) {
					closedd = w[i];
					minimumwater = u.second;
				}
			}
			//for every possible node neighbor to u
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (i != j && w[j] != weights[j] && w[i] != 0) {
						pair<tuple<int, int, int>, int> v = move(u, i, j);
						if (dist.find(v.first) != dist.end()) {
							if (dist[v.first] > v.second) {
								dist[v.first] = v.second;
								pq.push(v);
							}
						} else {
							dist[v.first] = v.second;
							pq.push(v);
						}
					}
				}
			}
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d %d %d", &weights[0], &weights[1], &weights[2], &d);
		dist.clear();
		found_d = false;
		minimumwater = (int) pow(2, 30);
		closedd = -1;
		dijkstra();
		if (found_d == true) {
			printf("%d %d\n", movedwater, d);
		} else {
			printf("%d %d\n", minimumwater, closedd);
		}
	}
	return 0;
}

