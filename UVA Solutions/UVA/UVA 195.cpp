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
bool myfunc(char a, char b) {
	int delta = tolower(a) - tolower(b);
	return delta ? delta < 0 : a < b;
}
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		char x[110];
		scanf("%s", x);
		sort(x, x + strlen(x), myfunc);
		do {
			printf("%s\n", x);
		} while (next_permutation(x, x + strlen(x), myfunc));
	}
	return 0;
}
