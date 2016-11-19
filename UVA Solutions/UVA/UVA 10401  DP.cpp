#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <stdlib.h>
using namespace std;

int n;
char s[16];
int f[16];
long long dp[16][16];

bool check(int lp, int c, int r) {
	bool pre, next;

	if(c == 0)
		pre = true;
	else {
		pre = abs(r - lp) > 1;
	}

	if(c == n - 1 || f[c + 1] == -1)
		next = true;
	else {
		next = abs(r - f[c + 1]) > 1;
	}

	return next && pre;
}

bool isValid() {

	for(int i = 1; i < n; i++) {
			if(f[i] != -1 && f[i - 1] != -1 && abs(f[i] - f[i - 1]) <= 1) {
				return false;
			}
	}


	return true;
}

long long solve(int lp, int c) {
	if(c == n)
		return 1;

	if(dp[lp][c] != -1)
		return dp[lp][c];

	long long ans = 0;
	if(f[c] != -1) {
		ans = solve(f[c], c + 1);
	}
	else {
		for(int i = 0; i < n; i++) {
			if(check(lp, c, i)) {
				ans += solve(i, c + 1);
			}
		}
	}

	return dp[lp][c] = ans;
}

int main(int argc, char **argv) {
	char b[2];
	b[1] = '\0';

//	freopen("input.txt", "r", stdin);
	while(scanf("%s", s) != EOF) {
		n = strlen(s);
		if(n == 0)
			continue;
		for(int i = 0; i < n; i++) {
			if(s[i] != '?') {
				b[0] = s[i];
				f[i] = strtol(b, NULL, 16) - 1;
			}
			else {
				f[i] = -1;
			}
		}

		memset(dp, -1, sizeof dp);
		if(! isValid()) {
			cout<<0<<endl;
		}
		else
			cout<<solve(0, 0)<<endl;
//		for(int i = 0 ;i < n; i++)
//			cout<<f[i]<<endl;
	}
    return 0;
}
