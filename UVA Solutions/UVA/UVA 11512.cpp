#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007
#define ZERO 1e-9
using namespace std;
char s[1010], itc[4];
int a, b, cti[150];
struct node {
	int cnt;
	int start, end;
	node *arr[4];
	node() {
		arr[0] = arr[1] = arr[2] = arr[3] = NULL;
		cnt = 0;
		start = end = -1;
	}
};
class trie {
public:
	node *root;
	int left, right;
	int len = 0, f = 0;
	void add() {
		insert(a, root, a);
	}
	void solve() {
		solve(root, 0);
	}
private:
	void insert(int ind, node *r, int st) {
		if (ind == b + 1) {
			return;
		}
		if (r->arr[cti[(int) s[ind]]] == NULL) {
			r->arr[cti[(int) s[ind]]] = new node();
			r->arr[cti[(int) s[ind]]]->start = st;
			r->arr[cti[(int) s[ind]]]->end = ind;
		}
		if (ind <= b) {
			r->arr[cti[(int) s[ind]]]->cnt++;
			insert(ind + 1, r->arr[cti[(int) s[ind]]], st);
		}
	}
	void solve(node *r, int d) {
		if (r->cnt >= 2) {
			if (d > len) {
				len = d, f = r->cnt;
				left = r->start;
				right = r->end;
			}
		}
		for (int i = 0; i < 4; i++) {
			if (r->arr[i] != NULL) {
				solve(r->arr[i], d + 1);
			}
		}
	}
};
int main(int argc, char **argv) {
	cti[(int) 'A'] = 0, cti[(int) 'C'] = 1;
	cti[(int) 'G'] = 2, cti[(int) 'T'] = 3;
	itc[0] = 'A', itc[1] = 'C';
	itc[2] = 'G', itc[3] = 'T';
	freopen("in.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	int tc;
	scanf("%d", &tc);
	getchar();
	while (tc--) {
		trie *t = new trie();
		t->root = new node();
		gets(s);
		b = strlen(s) - 1;
		for (int i = 0; i <= b; i++) {
			a = i;
			t->add();
		}
		t->solve();
		if (t->f == 0) {
			cout<<"No repetitions found!"<<endl;
		} else {
			for (int i = t->left; i <= t->right; i++) {
				cout << s[i];
			}
			cout << " " << t->f << endl;
		}
	}
	return 0;
}
