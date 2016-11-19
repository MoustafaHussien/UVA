#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define inf 99999999
using namespace std;
int coins[110];
int dp[1000000];
int coinum;
void generate(int sum) {
	memset(dp, 127, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < coinum; i++) {
		for (int j = sum; j >= coins[i]; j--) {
			dp[j] = min(dp[j], dp[j - coins[i]] + 1);
		}
	}
}

int main() {
	int tc;
	freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	int target, sum;
	while (tc--) {
		scanf("%d", &target);
		scanf("%d", &coinum);
		sum = 0;
		for (int i = 0; i < coinum; i++) {
			scanf("%d", &coins[i]);
			sum = sum + coins[i];
		}
		memset(dp, -1, sizeof(dp));
		sort(coins, coins + coinum);
		generate(sum);
		for (int i = target; i <= sum; i++) {
			if (dp[i] < 99999999) {
				cout << i << " " << dp[i] << endl;
				break;
			}
		}
	}
}
