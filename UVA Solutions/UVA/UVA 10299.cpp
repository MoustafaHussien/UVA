//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
map<long long, bool> mark;
void factor(long long n) {
	mark.clear();
	for (long long i = 2; i < sqrt(n) + 1; i++) {
		if (n % i == 0) {
//			cout << i << endl;
			mark[i] = true;
		}
		while (n % i == 0) {
			n = n / i;
		}
	}
	if (n != 1) {
		mark[n] = true;
	}
}

int main(int argc, char **argv) {
	long long n;
	while (1) {
		cin >> n;
		if (n == 0) {
			return 0;
		} else if (n == 1) {
			cout << 0 << endl;
		} else {
			factor(n);
			double ans = n;
			for (map<long long, bool>::iterator it = mark.begin();
					it != mark.end(); it++) {
				ans = ans * (1 - (1.0 / (it->first * 1.0)));
			}
			cout << (long long) ans << endl;

		}
	}
}
