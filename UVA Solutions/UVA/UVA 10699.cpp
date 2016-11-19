#include <bits/stdc++.h>
using namespace std;
set<int> fact(long long a) {
	set<int> x;
	for (int i = 2; i < sqrt(a * 1.0); i++) {
		if (a % i == 0) {
			x.insert(i);
		}
		while (a % i == 0) {
			a = a / i;
		}
	}
	if (a >= 2) {
		x.insert(a);
	}
	return x;
}
int main(int argc, char **argv) {
	long long n;
	while (true) {
		cin >> n;
		if (n == 0) {
			return 0;
		}
		cout << n << " : ";
		cout << fact(n).size() << endl;
	}
}
