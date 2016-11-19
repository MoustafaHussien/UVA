//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n, m;
	while (scanf("%d", &n) == 1) {
		vector<int> v;
		int temp;
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			v.push_back(temp);
		}
		scanf("%d", &m);
		scanf("\n");
		sort(v.begin(), v.end());
		vector<int>::iterator low;
		int x = 99999999, y = 0;
		for (int k = 0; k < n; k++) {
			low = lower_bound(v.begin() + k + 1, v.end(), m - v[k]);
			if (m - v[k] == *low) {
				if (abs(x - y) > abs(v[k] - *low)) {
					x = v[k];
					y = m - v[k];
				}
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n", x, y);
		printf("\n");
	}
	return 0;
}
