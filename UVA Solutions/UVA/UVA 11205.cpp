//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <algorithm>
#include <string>
#include <stdio.h>
#include <iostream>
#include <cctype>
#include <cmath>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	int resut[tc];
	for (int e = 0; e < tc; e++) {
		int p, n;
		scanf("%d", &p);
		scanf("%d\n", &n);
		unsigned int a[n];
		unsigned int b[n];
		string x;
		char * pEnd;
		for (int j = 0; j < n; j++) {
			getline(cin, x);
			x.erase(std::remove(x.begin(), x.end(), ' '), x.end());
			a[j] = strtoul(x.c_str(), &pEnd, 2);
		}
		int min = 1000;
		for (int i = 0; i < pow(2, p); ++i) {
			for (int j = 0; j < n; j++) {
				b[j] = a[j] & i;
			}
			sort(b, b + n);
			bool z = true;
			for (int j = 0; j < n - 1; j++) {
				if (b[j] == b[j + 1]) {
					z = false;
					break;
				}
			}
			if (z) {
				int num = i;
				int count = 0;
				while (num > 0) {
					num &= (num - 1);
					count++;
				}

				if (count < min) {
					min = count;
				}
			}
		}
		resut[e] = min;
	}
	for (int i = 0; i < tc; i++) {
		printf("%d\n", resut[i]);
	}
	return 0;
}
