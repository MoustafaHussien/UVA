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
int numbers[5];
char operations[4];
bool found() {
	int x[5];
	for (int i = 0; i < 5; i++) {
		x[i] = numbers[i];
	}
	do {
		int sum = x[0];
		for (int i = 0; i < 4; i++) {
			if (operations[i] == '*') {
				sum = sum * x[i + 1];
			}
			if (operations[i] == '+') {
				sum = sum + x[i + 1];
			}
			if (operations[i] == '-') {
				sum = sum - x[i + 1];
			}
		}
		if (sum == 23) {
			return true;
		}
	} while (next_permutation(x, x + 5));
	return false;
}

int main() {
	while (true) {
		char x[] = { '*', '-', '+' };
		for (int i = 0; i < 4; i++) {
			scanf("%d ", &numbers[i]);
		}
		scanf("%d", &numbers[4]);
		if (numbers[0] == 0 && numbers[1] == 0 && numbers[2] == 0
				&& numbers[3] == 0 && numbers[4] == 0) {
			return 0;
		}
		sort(numbers, numbers + 5);
		bool notfound = true;
		for (int i = 0; i < 3 && notfound; i++) {
			for (int j = 0; j < 3 && notfound; j++) {
				for (int k = 0; k < 3 && notfound; k++) {
					for (int l = 0; l < 3 && notfound; l++) {
						operations[0] = x[i];
						operations[1] = x[j];
						operations[2] = x[k];
						operations[3] = x[l];
						if (found()) {
							notfound = false;
							break;
						}
					}
				}
			}
		}
		if (notfound) {
			printf("Impossible\n");
		}
		if (!notfound) {
			printf("Possible\n");
		}
	}
	return 0;
}
