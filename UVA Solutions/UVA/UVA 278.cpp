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
	int t;
	char r;
	char zeft[100];
	int m, n;
	scanf("%d", &t);
	gets(zeft);
	while (t--) {
		gets(zeft);
		sscanf(zeft, "%c %d %d", &r, &n, &m);
		switch (r) {
		case 'r':
			if (n > m) {
				printf("%d\n", m);
			} else {
				printf("%d\n", n);
			}
			break;
		case 'k':
			printf("%d\n", ((n * m) + 1) / 2);
			break;
		case 'K':
			printf("%d\n", ((n + 1) * (m + 1)) / 4);
			break;
		case 'Q':
			if (n > m) {
				printf("%d\n", m);
			} else {
				printf("%d\n", n);
			}
			break;
		default:
			break;
		}
	}
	return 0;
}
