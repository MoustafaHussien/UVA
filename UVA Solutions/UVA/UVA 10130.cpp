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
int tc, n, people;
int price[1010];
int weight[1010];
int dp[1010][35];
int solve(int id, int w) {
	if (id >= n || w == 0)
		return 0;
	if (dp[id][w] != -1)
		return dp[id][w];
	if (weight[id] > w)
		return dp[id][w] = solve(id + 1, w);
	else
		return dp[id][w] = max(solve(id + 1, w),
				price[id] + solve(id + 1, w - weight[id]));

}

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		memset(dp, -1, sizeof(dp));
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d %d", &price[i], &weight[i]);
		scanf("%d", &people);
		int ans = 0;
		int mw;
		while (people--) {
			scanf("%d", &mw);
			ans += solve(0, mw);
		}
		printf("%d\n", ans);
	}
	return 0;
}
