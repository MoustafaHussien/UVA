#include <bits/stdc++.h>
using namespace std;
string clear(string a) {
	for (int i = 0; i < (int) a.size(); i++) {
		a[i] = tolower(a[i]);
		if (a[i] == '-')
			continue;
		if (tolower(a[i]) < 97 || tolower(a[i]) > 122) {
//			cout<<a[i]<<endl;
			a.erase(a.begin() + i);
			i--;
		}
	}
	return a;
}
int main(int argc, char **argv) {
	int ans = 0;
	string a, b;
	while (cin >> a) {
		if (a == "E-N-D") {
			break;
		}
		a = clear(a);
//		cout << a << endl;
		if ((int) a.length() > ans) {
			ans = a.length();
			b = a;
		}
	}
	cout << b << endl;
}
