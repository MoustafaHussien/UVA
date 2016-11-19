//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
long long d[] = { 1, 0, 1, 2, 9, 44, 265, 1854, 14833, 133496, 1334961,
		14684570, 176214841, 2290792932, 32071101049, 481066515734,
		7697064251745, 130850092279664, 2355301661033953, 44750731559645106,
		895014631192902121, 18795307255050944540 };

int solve(int n, int l) {
	if (n == l) {
		return 1;
	}
	long long ans = 1;
	l = min(n - l, l);
	for (int i = n - l + 1, j = 1; i <= n; i++, j++) {
		ans = ans * i;
		ans = ans / j;
	}
	return ans;
}

int main() {
	int n;
	int l;
	while (scanf("%d %d", &n, &l) != EOF) {
		long long result = 0;
		for (int i = l; i >= 0; i--) {
			result = result + (solve(n, i) * d[n - i]);
		}
		printf("%lld\n", result);
	}
	return 0;
}
