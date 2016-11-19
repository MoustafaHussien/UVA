#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
long long n;
vector<long long> fact(long long a) {
	vector<long long> ans;
	for (long long i = 2; i < sqrt(a * 1.0); i++) {
		if (a % i == 0) {
			long long x = 1;
			while (a % i == 0) {
				a = a / i;
				x = x * i;
			}
			ans.push_back(x);
		}
	}
	if (a >= 2) {
		ans.push_back(a);
	}
	return ans;
}
int main(int argc, char **argv) {
	long long x, tc;
	tc = 1;
	while (true) {
		cin >> x;
		if (x == 0) {
			return 0;
		}
		cout << "Case " << tc << ": ";
		v = fact(x);
		if (x == 1) {
			cout << 2 << endl;
		} else if (v.size() == 1) {
			cout << x + 1 << endl;
		} else {
			long long y = 0;
			for (long long i = 0; i < (long long) v.size(); i++) {
				y += v[i];
			}
			cout << y << endl;
		}
		v.clear();
		tc++;
	}
}

