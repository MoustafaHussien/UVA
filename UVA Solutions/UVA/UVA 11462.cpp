#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

int main() {

	while (1) {

		int t;
		scanf("%d", &t);
		if (t == 0)
			return 0;

		map<int, int> m;
		for (int i = 0; i < t; i++) {
			int x;
			scanf("%d ", &x);
			m[x] = m[x] + 1;
		}

		printf("%d", m.begin()->first);
		m.begin()->second = m.begin()->second - 1;

		for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
			for (int i = 0; i < it->second; i++)
				printf(" %d", it->first);
		}
		printf("\n");

	}

	return 0;
}
