//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int n, b, h, w, p;
	while (scanf("%d %d %d %d", &n, &b, &h, &w) !=EOF) {
		int cost = 5000000;
		bool found = false;
		int a[w];
		for (int i = 0; i < h; i++) {
			scanf("%d", &p);
			for (int i = 0; i < w; i++) {
				scanf("%d", &a[i]);
			}
			bool t = false;
			for (int j = 0; j < w; j++) {
				if (a[j] >= n) {
					t = true;
					break;
				}
			}
			if (t == true) {
				int temp = n * p;
				if (temp <= b && temp < cost) {
					cost = temp;
					found = true;
				}
			}
			t = false;

		}

		if (found == false) {
			printf("stay home\n");
		} else {
			printf("%d\n", cost);
		}
		found = false;
		cost = 5000000;
	}
	return 0;
}
