#include <bits/stdc++.h>
using namespace std;
bool check(string a, string b) {
	string c = "";
	while ((int) c.size() < (int) b.size()) {
		c = c + a;
	}
	if (c == b)
		return true;
	return false;
}
int main(int argc, char **argv) {
	int tc;
	cin >> tc;
	while (tc--) {
		string a;
		cin >> a;
		int cnt = 999;
		bool go = true;
		for (int i = 1; i <= (int) a.size() && go; i++) {
			if (a.size() % i == 0 && check(a.substr(0, i), a)) {
				cnt = i;
				go = false;
			}
		}
		cout << cnt << endl;
		if (tc > 0)
			cout << "\n";
	}
}

