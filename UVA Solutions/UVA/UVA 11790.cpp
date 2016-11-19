//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;
int tc, n, w[10000], h[10000], lis[10000], lds[10000], maxm = 0;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &h[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &w[i]);
		if (n == 1) {
			printf("Case %d. Increasing (%d). Decreasing (%d).\n", t, w[0],
					w[0]);
		} else {
			lis[0] = w[0];
			int maxlis = w[0];
			for (int i = 1; i < n; i++) {
				maxm = 0;
				for (int j = 0; j < i; j++) {
					if (h[i] > h[j]) {
						maxm = max(maxm, lis[j]);
					}
				}
				lis[i] = w[i] + maxm;
				maxlis = max(maxlis, lis[i]);
			}
			int maxlds = w[n - 1];
			lds[n - 1] = w[n - 1];
			maxm = 0;
			for (int i = n - 2; i > -1; i--) {
				maxm = 0;
				for (int j = i + 1; j < n; j++) {
					if (h[j] < h[i])
						maxm = max(maxm, lds[j]);
				}
				lds[i] = maxm + w[i];
				maxlds = max(maxlds, lds[i]);
			}
			if (maxlis >= maxlds)
				printf("Case %d. Increasing (%d). Decreasing (%d).\n", t,
						maxlis, maxlds);
			else {
				printf("Case %d. Decreasing (%d). Increasing (%d).\n", t,
						maxlds, maxlis);
			}
		}
	}
	return 0;
}
