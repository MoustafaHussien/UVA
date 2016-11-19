#include <bits/stdc++.h>
using namespace std;
#define MAX_N 15
string t, p;
int b[MAX_N], n, m;

void kmppreprocess() {
	int i = 0, j = -1;
	b[0] = -1;
	while (i < m) {
		while (j >= 0 && p[i] != p[j])
			j = b[j];
		i++;
		j++;
		b[i] = j;
	}
}

bool kmpSearch() {
	int i = 0, j = 0;
	while (i < n) {
		while (j >= 0 && t[i] != p[j])
			j = b[j];
		i++;
		j++;
		if (j == m) {
			if (i == j)
				return true;
			return false;
		}
		if (i > m) {
			return false;
		}
	}
	return false;
}

int main(int argc, char **argv) {
	vector<string> x;
	int a, tc;
	cin >> tc;
	string s;
	while (tc--) {
		cin >> a;
		x.clear();
		for (int i = 0; i < a; i++) {
			cin >> s;
			x.push_back(s);
		}
		sort(x.begin(), x.end());
		bool ans = true; //true is yes;
		for (int i = 0; i < a - 1 && ans; i++) {
			p = x[i];
			m = p.size();
			kmppreprocess();
			t = x[i + 1];
			n = t.size();
			if (n >= m && kmpSearch() == true) {
				ans = false;
			}
		}
		if (ans)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
