#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD n00000007
#define EPS 1e-9
#define  MAX_V 100
#define EQUALE(a, b) (fabs(a - b) < ESP)
using namespace std;
unordered_map<string, int> a;
int num[6];
vector<pair<int, int> > v;
int n, m;
void debug() {
	for (int i = 0; i < 6; i++)
		cout << num[i] << " ";
	cout << endl;
}
bool solve(int ind) {
	if (ind == m)
		return true;
	bool ret = 0;
	if (num[v[ind].first] > 0) {
		num[v[ind].first]--;
		ret = ret | solve(ind + 1);
		num[v[ind].first]++;
	}
	if (ret)
		return ret;
	if (num[v[ind].second] > 0) {
		num[v[ind].second]--;
		ret = ret | solve(ind + 1);
		num[v[ind].second]++;
	}
	return ret;
}
int main(int argc, char **argv) {
	freopen("in.txt", "r", stdin);
	string b, c;
	a["XXL"] = 0, a["XL"] = 1, a["L"] = 2, a["M"] = 3, a["S"] = 4, a["XS"] = 5;
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 0; i < 6; i++)
			num[i] = n / 6;
		v.clear();
		for (int i = 0; i < m; i++) {
			cin >> b >> c;
			v.push_back(make_pair(a[b], a[c]));
		}
		if (solve(0))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
