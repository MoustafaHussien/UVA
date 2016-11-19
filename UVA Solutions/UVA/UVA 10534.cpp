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
#include <vector>
using namespace std;

int main() {
	int n, temp;
	//freopen("input.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		vector<int> x;
		int l = 0, lis[n], lds[n], m[n + 1], lo, hi, mid, newl;
		//scan
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			x.push_back(temp);
		}
		//longest increasing sequence
		for (int i = 0; i < n; i++) {
			lo = 1;
			hi = l;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (x[m[mid]] < x[i])
					lo = mid + 1;
				else
					hi = mid - 1;
			}
			newl = lo;
			m[newl] = i;
			if (newl > l)
				l = newl;
			lis[i] = newl;
		}
		reverse(x.begin(), x.end());
		l = 0;
		for (int i = 0; i < n; i++) {
			lo = 1;
			hi = l;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (x[m[mid]] < x[i])
					lo = mid + 1;
				else
					hi = mid - 1;
			}
			newl = lo;
			m[newl] = i;
			if (newl > l)
				l = newl;
			lds[i] = newl;
		}
		reverse(lds, lds + n);
		int maxx = -1;
		for (int i = 0; i < n; i++) {
			if (min(lis[i], lds[i]) > maxx) {
				maxx = min(lis[i], lds[i]);
			}
		}
		printf("%d\n", (maxx * 2 - 1));
	}
	return 0;
}
