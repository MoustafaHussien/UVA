#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007
#define ZERO 1e-9
using namespace std;
string s;
bool check(int i, int j) {
	while (i < j) {
		if (s[i] != s[j])
			return 0;
		i++, j--;
	}
	return 1;
}
int main(int argc, char **argv) {
	ios_base::sync_with_stdio(0);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> s;
		bool alin = 0;
		for (int i = 0; i < (int) s.size() - 1; i++) {
			if (check(0, i) && check(i + 1, (int) s.size() - 1)) {
				alin = 1;
				break;
			}
		}
		if (alin)
			cout << "alindrome\n";
		else if (check(0, (int) s.size() - 1))
			cout << "palindrome\n";
		else
			cout << "simple\n";
	}
	return 0;
}
