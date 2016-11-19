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

int main() {
	long y, p;
	while (scanf("%ld", &y) == 1) {
		scanf("%ld", &p);
		long popes[p];

		for (long i = 0; i < p; i++) {
			scanf("%ld", &popes[i]);
		}

		int counter = 0;
		int x, z;
		for (int i = 0; i < p; i++) {
			int j = i;
			int sum = 0;
			int max, min, count = 0;
			while (sum < y && j < p - 1) {
				max = popes[i];
				sum = sum + popes[j + 1] - popes[j];
				min = popes[j];
				count++;
				j++;
			}
			if (count > counter) {
				counter = count;
				x = min;
				z = max;
			}
		}
		printf("%d %d %d\n", counter, z, x);
	}
	return 0;
}
