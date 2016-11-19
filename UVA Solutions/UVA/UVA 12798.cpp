#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
	freopen("input.txt","r",stdin);
	int n, m, a;
	while (cin >> n >> m) {
		int ans = 0;
		bool b;
		for (int i = 0; i < n; i++) {
			b = true;
			for (int j = 0; j < m; j++) {
				cin >> a;
				if (a == 0)
					b = false;
			}
			if (b)
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
