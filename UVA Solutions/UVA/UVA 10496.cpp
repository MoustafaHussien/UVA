//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <string.h>
#include <bitset>
using namespace std;
int x_size, y_size, startx, starty, n;
pair<int, int> beers[11];
int calc_moves(int i, int x, int y) {
	int temp = abs(beers[i].first - x) + abs(beers[i].second - y);
	return temp;
}
int dp[21][21][2048];
int solve(int x, int y, int mymask) {
	bitset<11> m(mymask); // 10 bits in this case
	if ((int) m.count() == n) {
		return abs(startx - x) + abs(starty - y);
	}
	int ans = 9999999;
	int dist;
	if (dp[x][y][mymask] != -1) {
		return dp[x][y][mymask];
	}
	for (int i = 0; i < n; i++) {
		if (m[i] == 0) {
			bitset<11> t = m;
			t[i] = 1;
			dist = calc_moves(i, x, y);
			ans = min(ans,
					solve(beers[i].first, beers[i].second, (int) t.to_ulong())
							+ dist);
		}
	}
	return dp[x][y][mymask] = ans;
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> x_size >> y_size >> startx >> starty >> n;
		for (int i = 0; i < n; i++) {
			cin >> beers[i].first >> beers[i].second;
		}
		memset(dp, -1, sizeof dp);
		cout << "The shortest path has length ";
		cout << solve(startx, starty, 0) << endl;
	}
	return 0;
}
