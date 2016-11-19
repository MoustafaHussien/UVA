//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
map<int, int> factorize(int n) {
	map<int, int> factors;
	while (n % 2 == 0) {
		factors[2]++;
		n = n / 2;
	}
	for (int i = 3; i <= sqrt(n); i = i + 2) {
		while (n % i == 0) {
			factors[i]++;
			n = n / i;
		}
	}
	if (n > 2) {
		factors[n]++;
	}
	return factors;
}
int main(int argc, char **argv) {
	int a, c, ans, tc;
	cin >> tc;
	while (tc--) {
		cin >> a >> c;
		if (c % a != 0) {
			cout << "NO SOLUTION\n";
		} else {
			map<int, int> amp = factorize(a);
			map<int, int> cmp = factorize(c);
			ans = 1;
			for (map<int, int>::iterator it = cmp.begin(); it != cmp.end();
					++it) {
				if (amp[it->first] != it->second) {
					ans *= pow(it->first, it->second);
				}
			}
			cout << ans << endl;
		}
	}
}
