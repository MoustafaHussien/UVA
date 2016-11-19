//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;
int main() {
	int t;
	int tc = 1;
	int ind = 0;
	int a[100000];
	int lis[100000];
	while (true) {
		ind = 0;
		scanf("%d", &t);
		if (t == -1)
			return 0;
		a[ind] = t;
		ind++;
		while (true) {
			scanf("%d", &t);
			if (t == -1)
				break;
			a[ind] = t;
			ind++;
		}
		memset(lis, -1, sizeof(lis));
		lis[ind - 1] = 1;
		int maxm = 0;
		for (int i = ind - 2; i > -1; i--) {
			maxm = 0;
			for (int j = i + 1; j < ind; j++) {
				if (a[j] < a[i])
					maxm = max(maxm, lis[j]);
			}
			lis[i] = maxm + 1;
		}
		int ans = -1;
		for (int i = 0; i < ind; i++)
			ans = max(ans, lis[i]);
		if (tc > 1)
			printf("\n");
		printf("Test #%d:\n  maximum possible interceptions: %d\n", tc, ans);
		tc++;
	}
	return 0;
}
