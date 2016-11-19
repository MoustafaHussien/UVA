#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
	string b;
	string ans = "";
	while (getline(cin, b)) {
		if (b != "___________") {
			string c;
			for (int j = 0; j < (int) b.size(); j++) {
				if (b[j] == 'o')
					c.push_back('1');
				if (b[j] == ' ')
					c.push_back('0');

			}
			int v = 0;
			for (int k = 0; k < 8; k++) {
				if (c[k] == '1')
					v += pow(2, 8 - k - 1);
			}
			ans.push_back(char(v));
		}
	}
	for (int i = 0; i < (int) ans.size(); i++)
		cout << ans[i];
	return 0;
}
