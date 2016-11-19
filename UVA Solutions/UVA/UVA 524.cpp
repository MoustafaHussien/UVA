//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

bool used[20];
int solution[20];
int n;
map<int, int> primes;

void solve(int index) {
	if (index == n) {
		if (primes[solution[n - 1] + 1] == 0)
			return;
		for (int i = 0; i < n - 1; i++) {
			printf("%d ", solution[i]);
		}
		printf("%d\n", solution[n - 1]);
		return;
	}

	for (int i = 2; i <= n; i++) {
		if (!used[i] && primes[solution[index - 1] + i] != 0) {

			used[i] = true;
			solution[index] = i;
			solve(index + 1);
			used[i] = false;
		}
	}

}

int main() {
	primes[1] = 1;
	primes[2] = 1;
	primes[3] = 1;
	primes[5] = 1;
	primes[7] = 1;
	primes[11] = 1;
	primes[13] = 1;
	primes[17] = 1;
	primes[19] = 1;
	primes[23] = 1;
	primes[29] = 1;
	primes[31] = 1;
	primes[37] = 1;
	solution[0] = 1;
	int T = 0;
	while (scanf("%d", &n) != EOF) {
		if (T)
			printf("\n");
		printf("Case %d:\n", ++T);
		solve(1);
	}
	return 0;
}

