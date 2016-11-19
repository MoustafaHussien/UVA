#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <stdlib.h>
#include <map>
#include <stdio.h>
#include <vector>
using namespace std;
map<int, int> m;
long long dp[70001];
long long magic(int i) {
	if (i == 1) {
		return 0;
	}
	return magic(i - 1) + pow(10, i - 1) - 1;
}
long long getdigitnum(int num) {
	return log10(num) + 1;
}
long long getlenth(int indx) {
	return (getdigitnum(indx) * indx) - magic(getdigitnum(indx));
}
void solve() {
	dp[1] = getlenth(1);
	for (int i = 2; i < 70000; i++) {
		dp[i] = dp[i - 1] + getlenth(i);
	}
}
int main(int argc, char **argv) {
	int tc;
	solve();
	cin >> tc;
	while (tc--) {
		int n, l = 69900, r = 1, m;
		cin >> n;
		if (n == 1) {
			cout << 1 << endl;
		} else {
			bool go = true;
			long long temp;
			while (l - r > 1) {
				m = (l + r) / 2;
				temp = dp[m];
				if (temp < n) {
					r = m;
				}
				if (temp > n) {
					l = m;
				}
				if (temp == n) {
					go = false;
					break;
				}
			}
			char a[100000];
			if (go) {
				int newindx = n - dp[r];
				for (int i = 1; i < 70000; i++) {
					sprintf(a, "%d", i);
					if ((int) strlen(a) < newindx) {
						newindx = newindx - strlen(a);
					} else {
						cout << a[newindx - 1] << endl;
						break;
					}
				}
			} else {
				sprintf(a, "%d", r + 1);
				cout << a[0] << endl;
			}
		}
	}
	return 0;
}
