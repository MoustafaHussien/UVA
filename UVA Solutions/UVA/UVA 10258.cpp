//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int f = 1; f <= t; f++) {
		map<char, int> x;
		int r, c, m, n;
		scanf("%d %d %d %d\n", &r, &c, &m, &n);
		for (int i = 0; i < r; i++) {
			char y[c];
			gets(y);
			for (int j = 0; j < c; j++) {
				x[y[j]] = x[y[j]] + 1;
			}
		}

		int max = -1;
		int repetation = 0;
		for (map<char, int>::iterator it = x.begin(); it != x.end(); it++) {
			if (it->second > max) {
				max = it->second;
				repetation = 1;
			}

			else if (it->second == max)
				repetation++;
		}
		int result = 0;
		result = max * repetation * m;
		result = result + (n * ((r * c) - (max * repetation)));
		printf("Case %d: %d\n", f, result);
	}
	return 0;
}
