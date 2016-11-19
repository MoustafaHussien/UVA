//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, q;
	int count = 1;
	while (true) {
		scanf("%d %d", &n, &q);
		if (n == 0 && q == 0) {
			return 0;
		}
		vector<int> v;
		int temp;
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			v.push_back(temp);
		}
		v.push_back(-1);
		v.push_back(999999);
		sort(v.begin(), v.end());
		vector<int>::iterator low;
		printf("CASE# %d:\n", count);
		count++;
		int x;
		for (int i = 0; i < q; i++) {
			scanf("%d", &x);
			low = lower_bound(v.begin(), v.end(), x);
			if (x != *low || *low == -1 || *low == 999999) {
				printf("%d not found\n", x);
			} else {
				printf("%d found at %d\n", x, (low - v.begin()));
			}
		}
		v.clear();
	}
	return 0;
}
