//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
int cubs[101][6], n, dp[501][101], choices[501][7];
map<int, int> opposite;
void setup() {
	opposite[0] = 1;
	opposite[1] = 0;
	opposite[2] = 3;
	opposite[3] = 2;
	opposite[4] = 5;
	opposite[5] = 4;
}

int solve(int i, int c) {
	if (dp[i][c] != -1) {
		return dp[i][c];
	}
	if (i == n - 1) {
		return 1;
	}
	int ans = solve(i + 1, c);
	for (int j = 0; j < 6; j++) {
		if (cubs[i + 1][j] == c) {
			if (ans < solve(i + 1, cubs[i + 1][opposite[j]]) + 1) {
				ans = solve(i + 1, cubs[i + 1][opposite[j]]) + 1;
			}
		}
	}
	return dp[i][c] = ans;
}

int main() {
	setup();
	freopen("input.txt", "r", stdin);
	cin >> n;
	vector<int> temp;
	for (int i = 0; i < n; i++) {
		temp.push_back(-1);
		for (int j = 0; j < 6; j++) {
			cin >> cubs[i][j];
		}
	}
	int ans = 0;
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < 6; i++) {
		if (ans < solve(0, cubs[0][i])) {
			ans = solve(0, cubs[0][i]);
		}
	}
	cout << "ans = " << ans << endl;
	return 0;
}

