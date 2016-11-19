#include <bits/stdc++.h>
using namespace std;
//number-of-zeros(10*N+C) = 10*(number-of-zeros(N)-1) + N - (9-C)*Z + 1
long long calc(long long n) {
	long long cnt = 0;
	while (n > 1) {
		if (n % 10 == 0)
			cnt++;
		n = n / 10;
	}
	return cnt;
}
long long f(long long m) {
	if (m < 0)
		return 0;
	if (m <= 9)
		return 1;
	long long n = m / 10;
	long long c = m - n * 10;
	long long ret = n + 1;
	ret += (10 * f(n) - 10);
	if (c != 9) {
		ret -= (9 - c) * calc(n);
	}
	return ret;
}

int main(int argc, char **argv) {
	long long a, b;
	while (1) {
		cin >> a >> b;
		if (a == -1 && b == -1)
			return 0;
		cout << f(b) - f(a - 1) << endl;
	}
	return 0;
}

