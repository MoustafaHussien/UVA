#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007
#define ZERO 1e-9
using namespace std;
class kmp {
public:
	string t, p;
	int b[2000000], n, m;
	void kmppreprocess() {
		int i = 0, j = -1;
		b[0] = -1;
		while (i < m) {
			while (j >= 0 && p[i] != p[j])
				j = b[j];
			i++, j++, b[i] = j;
		}
	}
	void kmpSearch() {
		kmppreprocess();
		bool f = 0;
		int i = 0, j = 0;
		while (i < n) {
			while (j >= 0 && t[i] != p[j])
				j = b[j];
			i++, j++;
			if (j == m) {
				if (f) {
					cout << p.size() / (i - j) << endl;
					return;
				}
				f = 1;
				j = b[j];
			}
		}
	}

private:
};
int main(int argc, char **argv) {
	string s;
	while (1) {
		cin >> s;
		if (s[0] == '.')
			return 0;
		string t = s + s;
		kmp *k = new kmp();
		k->n = t.size(), k->m = s.size(), k->t = t, k->p = s;
		k->kmpSearch();
	}
	return 0;
}
