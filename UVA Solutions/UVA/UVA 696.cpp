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
int f(int x) {
	if (x == 1)
		return 2;
	if (x == 2 || x == 3)
		return 4;
	return 0;
}

int main() {
	int x, y, z;
	while (true) {
		scanf("%d %d", &x, &y);
		if (x == 0 && y == 0)
			break;
		if (x == 1 || y == 1) {
			z = x * y;
		} else {
			if (x == 2 || y == 2) {
				z = (x * y) / 2;
				z = int(z / 4) * 4 + f(z % 4);
			} else {
				z = x * y;
				z = (z + 1) / 2;
			}
		}
		printf("%d knights may be placed on a %d row %d column board.\n", z, x,
				y);
	}
	return 0;
}
