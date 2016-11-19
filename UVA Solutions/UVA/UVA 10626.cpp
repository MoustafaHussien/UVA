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
short c, n1, n5, n10, basecase;
short dp[1100][100][50];
short solve(short ones, short fives, short tens) {
//	cout << ones << " " << fives << endl;
	if (ones + (5 * fives) + (10 * tens) == basecase) {
//		cout << "here " << ones << " " << fives << " " << basecase << endl;
		return 0;
	}
	if (dp[ones][fives][tens] != -1) {
		return dp[ones][fives][tens];
	}
	int ans = 100000000;
	if (tens > 0) {
		ans = min(ans, 1 + solve(ones + 2, fives, tens - 1));
	}
	if (ones >= 3 && tens > 0) {
		ans = min(ans, 4 + solve(ones - 3, fives + 1, tens - 1));
	}
	if (ones >= 8) {
		ans = min(ans, 8 + solve(ones - 8, fives, tens));
	}
	if (fives >= 2) {
		ans = min(ans, 2 + solve(ones + 2, fives - 2, tens));
	}
	if (ones >= 3 && fives >= 1) {
		ans = min(ans, 4 + solve(ones - 3, fives - 1, tens));
	}
	return dp[ones][fives][tens] = ans;
}
int main() {
	short test;
	freopen("input.txt", "r", stdin);
	cin >> test;
	while (test--) {
		cin >> c >> n1 >> n5 >> n10;
		short ans = 0;
		basecase = n1 + (n5 * 5) + (n10 * 10) - c * 8;
		memset(dp, -1, sizeof dp);
		ans += solve(n1, n5, n10);
		cout << ans << endl;
	}
	return 0;
}
