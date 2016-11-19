//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <stdlib.h>
#include <string>

using namespace std;

int main() {
	int n;
	while (true) {
		map<string, int> m;
		scanf("%d", &n);
		if (n == 0) {
			return 0;
		}
		for (int i = 0; i < n; i++) {
			int x[5];
			scanf("%d %d %d %d %d", &x[0], &x[1], &x[2], &x[3], &x[4]);
			sort(x, x + 5);
			char s[25];
			sprintf(s, "%d%d%d%d%d", x[0], x[1], x[2], x[3], x[4]);
			m[s] = m[s] + 1;
		}
		int max = -1;
		int repetation = 0;
		for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
			if (it->second > max) {
				max = it->second;
				repetation = 1;
			}

			else if (it->second == max)
				repetation++;
		}
		printf("%d\n" ,max*repetation);
	}
	return 0;
}
