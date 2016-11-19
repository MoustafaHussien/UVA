//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <map>
#include <fstream>
using namespace std;

int main() {
	int count = 0;
	map<int, pair<int, int> > z;
	for (int i = 0; i < 224; i++) {
		for (int j = 0; j < 224; j++) {
			z[(i * i) + (j * j)].first = i;
			z[(i * i) + (j * j)].second = j;
			count++;
		}
	}
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		int n;
		scanf("%d", &n);
		if (n == 0) {
			printf("0 0 0\n");
		} else {
			bool notfound = true;
			for (int i = 0; i <= 223 && n - (i * i) > 0 && notfound; i++) {
				if (z.count(n - (i * i))) {
					notfound = false;
					int a = z[n - (i * i)].first;
					int b = z[n - (i * i)].second;
					int c = (int) sqrt(n - (a * a) - (b * b));
					int r[] = { a, b, c };
					sort(r, r + 3);
					printf("%d %d %d\n", r[0], r[1], r[2]);
				}
			}
			if (notfound) {
				printf("-1\n");
			}
		}
	}
	return 0;
}
