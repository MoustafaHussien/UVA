//============================================================================
// name        : UVa.cpp
// author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int a[2001], lis[2001], lds[2001];
int n, tc;

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	for (int t = 0; t < tc; t++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (int i = n - 1; i > -1; i--) {
			int maxx = 0;
			for (int j = i + 1; j < n; j++) {
				if (a[i] < a[j]) {
					maxx = max(lis[j], maxx);
				}
			}
			lis[i] = 1 + maxx;
		}
		for (int i = n - 1; i > -1; i--) {
			int maxx = 0;
			lds[i] = 1;
			for (int j = i + 1; j < n; j++) {
				if (a[i] > a[j]) {
					maxx = max(maxx, lds[j]);
				}
			}
			lds[i] = 1 + maxx;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, lis[i] + lds[i] - 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}
