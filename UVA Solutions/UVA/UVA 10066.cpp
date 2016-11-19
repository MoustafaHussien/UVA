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
using namespace std;
int a[101], b[101], dp[101][101][101], n1, n2;
int solve(int i, int j, int length) {
	if (i == n1 || j == n2) {
		return length;
	}
	if (dp[i][j][length] != -1) {
		return dp[i][j][length];
	}
	if (a[i] == b[j]) {
		return dp[i][j][length] = solve(i + 1, j + 1, length + 1);
	} else {
		return dp[i][j][length] = max(solve(i + 1, j, length),
				solve(i, j + 1, length));
	}
}
int main() {
	int t = 1;
	freopen("input.txt", "r", stdin);
	while (true) {
		scanf("%d %d", &n1, &n2);
		if (n1 == 0 && n2 == 0) {
			return 0;
		}
		for (int i = 0; i < n1; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n2; i++) {
			scanf("%d", &b[i]);
		}
		memset(dp, -1, sizeof dp);
		cout << "Twin Towers #" << t << endl;
		cout << "Number of Tiles : " << solve(0, 0, 0) << endl;
		cout << "\n";
		t++;
	}
	return 0;
}
