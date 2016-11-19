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
#include <stdlib.h>
using namespace std;
int tracks[25];
bool result[25];
bool temp[25];
int n, t;
int x = -1;
int length = -1;
void solve(int index, int sum) {
	if (sum > n) {
		return;
	}
	/*if (sum == x) {
	 int count = 0;
	 for (int i = 0; i < index; i++) {
	 if (temp[i] == true) {
	 count++;
	 }
	 }
	 if (count > length) {
	 x = sum;
	 for (int i = 0; i < t; i++) {
	 result[i] = temp[i];
	 }
	 length = count;
	 }
	 }
	 */else if (sum > x) {
		x = sum;
		for (int i = 0; i < t; i++) {
			result[i] = temp[i];
		}
	}

	for (int i = index; i < t; i++) {
		if (!temp[i]) {
			temp[i] = true;
			solve(i, sum + tracks[i]);
			temp[i] = false;
		}
	}
}

int main() {
	while (scanf("%d %d", &n, &t) != EOF) {
		for (int i = 0; i < t; i++) {
			scanf("%d", &tracks[i]);
		}
		x = 0;
		length = -1;
		for (int i = 0; i < 20; i++) {
			temp[i] = false;
			result[i] = false;
		}

		solve(0, 0);
		for (int i = 0; i < t; i++) {
			if (result[i] == true) {
				printf("%d ", tracks[i]);
			}
		}
		printf("sum:%d\n", x);
	}
	return 0;
}
