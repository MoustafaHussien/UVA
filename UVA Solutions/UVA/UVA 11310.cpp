//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
map<pair<pair<bool, bool>, int>, long long> dp;
map<pair<pair<bool, bool>, int>, bool> v;
long long solve(pair<bool, bool> mask, int i) {
	if (mask.first + mask.second == 0 && i == n) {
		return 1;
	}
	if (i >= n) {
		return 0;
	}
	if (v[make_pair(mask, i)] == true) {
		return dp[make_pair(mask, i)];
	}
	v[make_pair(mask, i)] = true;
	long long ans = 0;
	pair<bool, bool> a;
	if (mask.first + mask.second == 0) {
		a.first = 1, a.second = 1;
		ans += 2 * solve(a, i + 1);
		a.first = 0, a.second = 1;
		ans += solve(a, i + 1);
		a.first = 1, a.second = 0;
		ans += solve(a, i + 1);
		a.first = 0, a.second = 0;
		ans += solve(a, i + 1);
	}
	if (mask.first + mask.second == 2) {
		a.first = 0, a.second = 0;
		ans += solve(a, i + 1);
	}
	if (mask.first + mask.second == 1) {
		a.first = 0, a.second = 0;
		ans += solve(a, i + 1);
		a.first = 1, a.second = 1;
		ans += solve(a, i + 1);
	}
	return dp[make_pair(mask, i)] = ans;
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		pair<bool, bool> a;
		dp.clear(), v.clear();
		a.first = false, a.second = false;
		cout << solve(a, 0) << endl;
	}
	return 0;
}
