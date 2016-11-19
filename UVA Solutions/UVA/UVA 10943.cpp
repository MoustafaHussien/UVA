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
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int i, j, t, dp[110][110], N, K;
	memset(dp, 0, sizeof dp);
	for (i = 0; i <= 100; i++)
		dp[i][1] = 1;

	for (j = 1; j <= 100; j++) { //loop on k
		for (i = 0; i <= 100; i++) //loop on n
			for (t = 0; t <= i; t++) {
				dp[i][j] += dp[i - t][j - 1];
				dp[i][j] %= 1000000;
			}
	}
	while (scanf("%d %d", &N, &K), (N || K))
		printf("%d\n", dp[N][K]);

	return 0;
}
