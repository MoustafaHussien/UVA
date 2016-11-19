#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
int n, m, k;
int main() {
	cin >> n >> m >> k;
	int a[n + 1], b[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[a[i]] = i;
	}

	int ans = 0;
	int f, tmp;
	for (int i = 0; i < m; i++) {
		cin >> f;
		ans++;
		int page = (int) ceil(b[f] / (float) k);
		if (page != 0)
			ans += page - 1;

		if (b[f] != 1) {
			tmp = a[b[f]];
			a[b[f]] = a[b[f] - 1];
			a[b[f] - 1] = tmp;
			b[f]--;
			b[a[b[f] + 1]]++;
		}
	}
	cout << ans << endl;
}

