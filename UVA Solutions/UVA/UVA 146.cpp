#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
	char x[100];
	while (1) {
		gets(x);
		if (x[0] == '#')
			return 0;
		if (next_permutation(x, x + strlen(x))) {
			printf(x);
			printf("\n");
		} else {
			printf("No Successor\n");
		}
	}
	return 0;
}
