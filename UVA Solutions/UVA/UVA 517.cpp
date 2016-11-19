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
	freopen("input.txt", "r", stdin);
	int ca, cb, n, na, nb;
	while (scanf("%d %d %d", &ca, &cb, &n) != EOF) {
		nb = 0, na = 0;
		while (nb != n) {
			if (na == 0) {
				na = ca;
				printf("fill A\n");
			}
			if (nb == cb) {
				printf("empty B\n");
				nb = 0;
			}
			printf("pour A B\n");
			nb = nb + na;
			if (nb > cb) {
				na = nb - cb, nb = cb;
			} else if (cb >= nb) {
				na = 0;
			}
		}
		printf("success\n");
	}
	return 0;
}
