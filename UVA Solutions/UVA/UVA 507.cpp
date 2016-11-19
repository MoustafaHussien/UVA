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
#include <math.h>
using namespace std;

int main() {
	int tc, s, a[20100];
	freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%d", &s);
		for (int i = 1; i < s; i++) {
			scanf("%d", &a[i]);
		}
		int maxSum = -9999999, maxStartIndex = 0, maxEndIndex = 0;
		int currentMaxSum = 0, currentStartIndex = 1;
		for (int currentEndIndex = 1; currentEndIndex < s; currentEndIndex++) {
			currentMaxSum = currentMaxSum + a[currentEndIndex];
			if (currentMaxSum > maxSum) {
				maxSum = currentMaxSum;
				maxStartIndex = currentStartIndex;
				maxEndIndex = currentEndIndex;
			} else if (currentMaxSum == maxSum) {
				if (currentEndIndex - currentStartIndex
						> maxEndIndex - maxStartIndex) {
					maxStartIndex = currentStartIndex;
					maxEndIndex = currentEndIndex;
				} else if (currentEndIndex - currentStartIndex
						== maxEndIndex - maxStartIndex) {
					if (currentStartIndex < maxStartIndex) {
						maxStartIndex = currentStartIndex;
						maxEndIndex = currentEndIndex;
					}
				}
			}
			if (currentMaxSum < 0) {
				currentMaxSum = 0;
				currentStartIndex = currentEndIndex + 1;
			}
		}
		if (maxSum > 0) {
			printf("The nicest part of route %d is between stops %d and %d\n",
					t, maxStartIndex, maxEndIndex + 1);
		} else {
			printf("Route %d has no nice parts\n", t);
		}
	}
	return 0;
}
