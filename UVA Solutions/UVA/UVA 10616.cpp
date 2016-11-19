#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int n, q, d, m;
long long dp[201][12][200];
long long a[201];
long long mod(long long number, int mod) {
	if (number >= 0)
		return number % mod;
	return (mod + (number % mod)) % mod;
}
long long solve(int indx, int num, int remd) {
	if (num == 0 && remd == 0)
		return 1;
	if (indx == n || num == 0)
		return 0;
	if (dp[indx][num][remd] != -1) {
		return dp[indx][num][remd];
	}
	return dp[indx][num][remd] = solve(indx + 1, num - 1,
			mod(remd + a[indx], d)) + solve(indx + 1, num, remd);
}

int main() {
	int tc = 1;
	freopen("input.txt", "r", stdin);
	while (true) {
		cin >> n >> q;
		if (n == 0 && q == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << "SET " << tc << ":" << endl;
		tc++;
		for (int i = 1; i <= q; i++) {
			cin >> d >> m;
			memset(dp, -1, sizeof(dp));
			printf("QUERY %d: %lld\n", i, solve(0, m, 0));
		}
	}
	return 0;
}
