//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	vector<int> x;
	int b;
	while (scanf("%d", &b) != EOF) {
		x.push_back(b);
	}
	int p[x.size()];
	int m[x.size() + 1];
	int l = 0, lo, mid, hi;
	for (int i = 0; i < (int) x.size(); i++) {
		lo = 1, hi = l;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (x[m[mid]] < x[i])
				lo = mid + 1;
			else
				hi = mid - 1;
		}
		int newL = lo;
		p[i] = m[newL - 1];
		if (newL > l) {
			m[newL] = i;
			l = newL;
		} else if (x[i] < x[m[newL]]) {
			m[newL] = i;
		}
	}
	int s[l];
	int k = m[l];
	for (int i = l - 1; i > -1; i--) {
		s[i] = x[k];
		k = p[k];
	}
	printf("%d\n-\n", l);
	for (int i = 0; i < l; i++)
		printf("%d\n", s[i]);
	return 0;
}
