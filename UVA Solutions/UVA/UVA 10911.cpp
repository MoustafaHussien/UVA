//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <bitset>
using namespace std;
double dp[131072];
bool calculate[131072];
int x[17], y[17], n;
double calcdistance(int i, int j) {
	return sqrt(pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2));
}

double solve(int mask) {
	if (mask == ((1 << n) - 1)) {
		return 0;
	}

	if (calculate[mask]) {
		return dp[mask];
	}
	double ans = 9999999999;
	for (int i = 0; i < n; i++) {
		if ((mask & (1 << i)) == 0) {
			for (int j = i + 1; j < n; j++) {
				if ((mask & (1 << j)) == 0) {
					mask |= 1 << i;
					mask |= 1 << j;
					ans = min(ans, solve(mask) + calcdistance(i, j));
					mask &= ~(1 << i);
					mask &= ~(1 << j);

				}
			}
		}
	}
	calculate[mask] = true;
	return dp[mask] = ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	string temp;
	double ans;
	int t = 1;
	while (true) {
		cin >> n;
		if (n == 0) {
			return 0;
		}
		n = n * 2;
		memset(calculate, false, sizeof calculate);
		for (int i = 0; i < n; i++) {
			cin >> temp;
			cin >> x[i];
			cin >> y[i];
		}
		ans = round(solve(0) * 100) / 100;
		cout << "Case " << t << ": ";
		t++;
		printf("%.2f\n", ans);
	}
	return 0;
}
