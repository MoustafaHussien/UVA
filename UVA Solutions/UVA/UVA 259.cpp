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
int sum[26], cnt;
vector<int> a[10];
string ans;
bool solve(int ind) {
	if (ind == 10) {
		return cnt == 0;
	}
	bool ret = solve(ind + 1);
	for (int i = 0; i < (int) a[ind].size() && !ret; i++) {
		if (sum[a[ind][i]] > 0) {
			sum[a[ind][i]]--, cnt--, ans[ind] = (char) 'A' + a[ind][i];
			ret = ret | solve(ind + 1);
			if (ret)
				return ret;
			sum[a[ind][i]]++, cnt++, ans[ind] = '_';
		}
	}
	return ret;
}
int main(int argc, char **argv) {
	freopen("in.txt", "r", stdin);
	char x[100];
	while (1) {
		if (gets(x) == 0)
			break;
		memset(sum, 0, sizeof(sum)), cnt = 0;
		ans = "__________";
		for (int i = 0; i < 26; i++)
			a[i].clear();
		do {
			sum[x[0] - 'A'] += x[1] - '0', cnt += sum[x[0] - 'A'];
			for (int i = 3; i < (int) strlen(x) - 1; i++)
				a[x[i] - '0'].push_back(x[0] - 'A');
		} while (gets(x) && strcmp(x, "") != 0);
		if (cnt > 10)
			cout << "!\n";
		else {
			bool x = solve(0);
			if (x)
				cout << ans << endl;
			else
				cout << "!\n";
		}
	}
	return 0;
}
