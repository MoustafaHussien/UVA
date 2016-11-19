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
#define ComeFromUp 0
#define ComeFromLeft 1
#define ComeFromRight 2
#define INF -9114861777597660799
int n, k, grid[80][80];
long long dp[80][80][10][3];
bool visits[80][80][10][3];
bool imp = true;
long long solve(int i, int j, int remain, int direction) {
	if (visits[i][j][remain][direction]) {
		return dp[i][j][remain][direction];
	}
	if ((remain == 0 && grid[i][j] < 0) || (i > n - 1) || (j > n - 1)) {
		return dp[i][j][remain][direction] = INF;
	}

	if (i == n - 1 && j == n - 1) {
		imp = false;
		return dp[i][j][remain][direction] = grid[i][j];
	}

	visits[i][j][remain][direction] = true;
	int a = remain;
	long long temp;
	long long choices[] = { -999999999, -999999999, -99999999 };
	if (grid[i][j] < 0) {
		a = remain - 1;
	}
	if (direction == ComeFromUp) {
		if (i < n - 1) {
			choices[0] = solve(i + 1, j, a, ComeFromUp);
		}
		if (j > 0) {
			choices[1] = solve(i, j - 1, a, ComeFromRight);
		}
		if (j <= n - 1) {
			choices[2] = solve(i, j + 1, a, ComeFromLeft);
		}

	} else if (direction == ComeFromLeft) {
		if (i < n - 1) {
			choices[0] = solve(i + 1, j, a, ComeFromUp);
		}
		if (j < n - 1) {
			choices[2] = solve(i, j + 1, a, ComeFromLeft);
		}
	} else if (direction == ComeFromRight) {
		if (i < n - 1) {
			choices[0] = solve(i + 1, j, a, ComeFromUp);
		}
		if (j > 0) {
			choices[1] = solve(i, j - 1, a, ComeFromRight);
		}
	}
	temp = max(max(choices[0], choices[1]), choices[2]);
	if (temp != INF && temp + grid[i][j] > dp[i][j][remain][direction]) {
		dp[i][j][remain][direction] = temp + grid[i][j];
	}
	//cout << dp[i][j][remain][direction] << "<<<<<<\n";
	return dp[i][j][remain][direction];
}
int main() {
	freopen("input.txt", "r", stdin);
	int tc = 1;
	while (true) {
		cin >> n >> k;
		if (n == k && n == 0) {
			return 0;
		}
		memset(visits, false, sizeof visits);
		memset(dp, -127, sizeof dp);
		imp = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> grid[i][j];
			}
		}
		long long ans = solve(0, 0, k, ComeFromUp);
		cout << "Case " << tc << ": ";
		if (imp) {
			cout << "impossible\n";
		} else {
			cout << ans << endl;
		}
		tc++;
	}
	return 0;
}
