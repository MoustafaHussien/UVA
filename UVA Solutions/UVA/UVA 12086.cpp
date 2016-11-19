#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007
#define ZERO 1e-9
using namespace std;
using namespace std;
class segment_tree {
public:
	struct node {
		long long sum;
	};
	node t[800000];
	int val[200001];
	void build(int n, int l, int r) {
		if (l == r) {
			t[n].sum = val[l];
			return;
		}
		int left = n << 1;
		int right = left + 1;
		int mid = (l + r) >> 1;
		build(left, l, mid), build(right, mid + 1, r);
		t[n].sum = t[left].sum + t[right].sum;
	}
	void update(int n, int s, int e, int i, int j, int v) {
		if (s == i && e == j) {
			t[n].sum = v;
			return;
		}
		int left = n << 1;
		int right = left + 1;
		int mid = (s + e) >> 1;
		if (i <= mid) {
			update(left, s, mid, i, j, v);
		} else if (i > mid) {
			update(right, mid + 1, e, i, j, v);
		} else {
			update(left, s, mid, i, mid, v);
			update(right, mid + 1, e, mid + 1, j, v);
		}
		t[n].sum = t[left].sum + t[right].sum;
	}
	long long query(int n, int s, int e, int i, int j) {
		if (s == i && e == j) {
			return t[n].sum;
		}
		int left = n << 1;
		int right = left + 1;
		int mid = (s + e) >> 1;
		if (j <= mid)
			return query(left, s, mid, i, j);
		if (i > mid)
			return query(right, mid + 1, e, i, j);
		return query(left, s, mid, i, mid)
				+ query(right, mid + 1, e, mid + 1, j);
	}
};
int main() {
//	freopen("out.out","w",stdout);
	segment_tree *t = new segment_tree();
	int n, x, y, r;
	int cnt = 1;
	bool line = 0;
	while (1) {
		cin >> n;
		if (n == 0)
			return 0;
		if (line)
			cout << "\n";
		line=1;
		cout << "Case " << cnt << ":\n";
		cnt++;
		for (int i = 1; i <= n; i++) {
			cin >> t->val[i];
		}
		t->build(1, 1, n);
		string s = "";
		while (1) {
			cin >> s;
			if (s == "END")
				break;
			if (s == "S") {
				cin >> x >> r;
				t->update(1, 1, n, x, x, r);
			} else {
				cin >> x >> y;
				cout << t->query(1, 1, n, x, y) << endl;
			}
		}
	}
	return 0;
}
