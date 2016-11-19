#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
	freopen("input.txt", "r", stdin);
	int n;
	map<string, int> m;
	string a;
	while (cin >> n >> a) {
		for (int i = 0; i < (int) a.size(); i++) {
			if (i + n <= (int) a.size()) {
				string b;
				for (int j = i; j < i + n; j++) {
					b.push_back(a[j]);
				}
				m[b]++;
			}
		}
		map<string, int>::iterator it;
		string ans;
		int maxi = -1;
		for (it = m.begin(); it != m.end(); it++) {
			if (it->second > maxi) {
				maxi = it->second;
				ans = it->first;
			}
		}
		cout << ans << endl;
		m.clear();
	}
	return 0;
}
