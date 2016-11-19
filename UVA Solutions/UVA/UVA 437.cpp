#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
struct block {
	int x, y, z;
	block(int a, int b, int c) {
		x = a, y = b, z = c;
	}
};
vector<block> w;
bool comp(block a, block b) {
	if (a.x < b.x) {
		return true;
	} else if (a.x == b.x && a.y < b.y) {
		return true;
	} else if (a.x == b.x && a.y == b.y && a.z < b.z) {
		return true;
	} else {
		return false;
	}
}
void print() {
	for (int i = 0; i < (int) w.size(); i++)
		printf("%d %d %d\n", w[i].x, w[i].y, w[i].z);
}
bool canbuild(int i, int j) {
	if (w[i].x > w[j].x && w[i].y > w[j].y) {
		return true;
	}
	if (w[i].x > w[j].y && w[i].y > w[j].x) {
		return true;
	}
	return false;
}
int main(int argc, char **argv) {
	int n, tc = 0;
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			return 0;
		w.clear();
		for (int i = 0; i < n; i++) {
			int a[3];
			scanf("%d %d %d", &a[0], &a[1], &a[2]);
			sort(a, a + 3);
			do {
				w.push_back(block(a[0], a[1], a[2]));
			} while (next_permutation(a, a + 3));
		}
		sort(w.begin(), w.end(), comp);
		int a[w.size()];
		int ans = -1;
		for (int i = 0; i < (int) w.size(); i++) {
			a[i] = w[i].z;
			for (int j = 0; j < i; j++) {
				if (canbuild(i, j)) {
					a[i] = max(a[i], a[j] + w[i].z);
				}
			}
			ans = max(ans, a[i]);
		}
		printf("Case %d: maximum height = %d\n", ++tc, ans);
	}
}

