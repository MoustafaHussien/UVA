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
using namespace std;
bool myfunction(int i, int j) {
	return (i > j);
}

int main() {
	int n, d, l;
	while (true) {
		scanf("%d %d %d", &n, &d, &l);
		if (n == 0 && d == 0 && l == 0) {
			return 0;
		}
		int day[n];
		int night[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", &day[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &night[i]);
		}
		sort(day, day + n);
		sort(night, night + n, myfunction);
		long sum = 0;
		long pay = 0;
		for (int i = 0; i < n; i++) {
			sum = day[i] + night[i];
			if (sum > d) {
				pay = pay + ((sum - d) * l);
			}
		}
		printf("%ld\n", pay);

	}
	return 0;
}
