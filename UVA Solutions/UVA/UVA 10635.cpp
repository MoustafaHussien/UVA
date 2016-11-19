//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>
using namespace std;
short n, p, q, a[62501], b[62501], indxofa[62501], indxofb[62501];
map<pair<short, short>, int> dp;
map<pair<short, short>, short> x;
int solve(short i, short j) {
	if (i >= p || j >= q) {
		return 0;
	}
	if (x[make_pair(i, j)] != 0) {
		return dp[make_pair(i, j)];
	}
	int ans = -1;
	if (a[i] == b[j]) {
		x[make_pair(i, j)] = 1;
		return dp[make_pair(i, j)] = solve(i + 1, j + 1) + 1;
	} else {
		if (indxofb[a[i]] != -1 && indxofb[a[i]] > j) {
			ans = max(ans, solve(i + 1, indxofb[a[i]] + 1) + 1);
		}
		if (indxofa[b[j]] != -1 && indxofa[b[j]] > i) {
			ans = max(ans, solve(indxofa[b[j]] + 1, j + 1) + 1);
		}
		x[make_pair(i, j)] = 1;
		return dp[make_pair(i, j)] = max(ans, solve(i + 1, j + 1));
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		memset(indxofa, -1, sizeof indxofa);
		memset(indxofb, -1, sizeof indxofb);
		dp.clear();
		x.clear();
		cin >> n >> p >> q;
		p++, q++;
		for (int i = 0; i < p; i++) {
			cin >> a[i];
			indxofa[a[i]] = i;
		}
		for (int i = 0; i < q; i++) {
			cin >> b[i];
			indxofb[b[i]] = i;
		}
		cout << "Case " << t << ": " << solve(0, 0) << endl;
	}
	return 0;
}
