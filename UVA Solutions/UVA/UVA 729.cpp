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
#include <string.h>
using namespace std;

int main() {
	int tc, n, h;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf("%d %d", &n, &h);
		char a[n];
		memset(a, '1', sizeof(a));
		for (int j =0; j< n-h; j++)
			a[j] = '0';
		if (i)
			printf("\n");
		do {
			for (int j = 0; j < n; j++)
				printf("%c", a[j]);
			printf("\n");
		} while (next_permutation(a, a + n));
	}
	return 0;
}
