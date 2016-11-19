#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007
#define ZERO 1e-9
#define MAX 5000000
using namespace std;
bitset<MAX + 2> p;
int sum[MAX + 2];
int ans[MAX + 2];
void seive() {
	p.set();
	memset(sum, 0, sizeof(sum));
	p[0] = p[1] = 0;
	for (long long i = 2; i <= MAX; i++) {
		if (p[i]) {
			sum[i] += i;
			for (long long j = i * 2; j <= MAX; j += i)
				sum[(int) j] += i, p[j] = 0;
		}
	}
	ans[0] = ans[1] = 0;
	for (int i = 2; i <= MAX; i++) {
		ans[i] = ans[i - 1];
		if (p[sum[i]])
			ans[i] += 1;
	}
}
int main(int argc, char **argv) {
	seive();
	int a, b;
	while (1) {
		cin >> a;
		if (a == 0)
			return 0;
		cin >> b;
		cout << ans[b] - ans[a - 1] << endl;
	}
	return 0;
}
