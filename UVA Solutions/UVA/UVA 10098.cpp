//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char a[15];
		cin >> a;
		sort(a, a + strlen(a));
		do {
			puts(a);
		} while (next_permutation(a, a + strlen(a)));
		printf("\n");
	}
	return 0;
}
