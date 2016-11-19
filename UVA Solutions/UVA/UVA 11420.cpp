//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#define ISLOCKED 0
#define ISOPEN 1
using namespace std;
long long n, s;
long long a[] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987,
		1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393,
		196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887,
		9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141,
		267914296, 433494437, 701408733, 1134903170, 1836311903, 2971215073,
		4807526976, 7778742049, 12586269025, 20365011074, 32951280099,
		53316291173, 86267571272, 139583862445, 225851433717, 365435296162,
		591286729879, 956722026041, 1548008755920, 2504730781961, 4052739537881,
		6557470319842, 10610209857723, 17167680177565, 27777890035288 };
//indexed from 1
long long dp[2][70][70];
long long solve(long long previous, long long i, long long r) {
	if (i >= n + 1 && r != 0) {
		return 0;
	}
	if (dp[previous][i][r] != -1) {
		return dp[previous][i][r];
	}
	if (r == 0 && i <= n + 1) {
		if (n - i > 0) {
			return a[n - i + 1];
		}
		return 1;
	}

	long long ans = 0;
	if (n - i - 1 >= r) {
		ans += solve(ISOPEN, i + 1, r);
	}
	if (previous == ISLOCKED) {
		ans += solve(ISLOCKED, i + 1, r - 1);

	} else {
		ans += solve(ISLOCKED, i + 1, r);
	}
	return dp[previous][i][r] = ans;
}

int main() {
	while (true) {
		memset(dp, -1, sizeof dp);
		cin >> n >> s;
		if (n < 0 && s < 0) {
			return 0;
		}
		cout << solve(ISLOCKED, 1, s) << endl;
	}
	return 0;
}
