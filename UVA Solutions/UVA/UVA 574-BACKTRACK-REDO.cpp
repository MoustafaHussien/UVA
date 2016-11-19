//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <sstream>
using namespace std;
int t;
int n;
int numbers[12];
bool check[12];
map<string, bool> m;
bool none = true;
void solve(int index, int sum) {
	if (sum == t) {
		ostringstream x;
		bool first = true;
		for (int i = 0; i < n; i++) {
			if (check[i] && first) {
				x << "" << numbers[i];
				first = false;
			} else if (check[i] && first == false) {
				x << "+" << numbers[i];
			}
		}
		m[x.str()] = true;
		none = false;
		return;
	}
	for (int i = index; i < n; i++) {
		if (!check[i]) {
			check[i] = true;
			solve(i, sum + numbers[i]);
			check[i] = false;
		}
	}
}

int main() {
	while (true) {
		scanf("%d %d", &t, &n);
		if (n == 0 && t == 0) {
			return 0;
		}
		for (int i = 0; i < n; ++i) {
			scanf("%d", &numbers[i]);
		}
		solve(0, 0);
		printf("Sums of %d:\n", t);
		if (none) {
			printf("NONE\n");
		} else {
			for (map<string, bool>::reverse_iterator iter = m.rbegin();
					iter != m.rend(); ++iter) {
				cout << iter->first << endl;
			}
		}
		m.clear();
		none = true;
		for (int i = 0; i < 12; i++) {
			numbers[i] = 0;
			check[i] = false;
		}
	}
	return 0;
}
