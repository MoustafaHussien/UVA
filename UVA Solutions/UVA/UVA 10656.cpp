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
	int n;
	while (true) {
		scanf("%d", &n);
		if (n == 0) {
			return 0;
		}
		int num[n];
		int temp, m = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			if (temp != 0) {
				num[m] = temp;
				m++;
			}
		}
		if (m == 0) {
			printf("0\n");
		} else {
			for (int i = 0; i < m - 1; i++) {
				printf("%d ", num[i]);
			}
			printf("%d\n", num[m - 1]);
		}
	}
	return 0;
}
