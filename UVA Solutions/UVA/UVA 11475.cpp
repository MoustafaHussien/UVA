#include <bits/stdc++.h>
using namespace std;
int b[300010];
void kmpPreprocess(string P, int m) {
	int i = 0, j = -1;
	b[0] = -1;
	while (i < m) {
		while (j >= 0 && P[i] != P[j])
			j = b[j];
		i++;
		j++;
		b[i] = j;
	}
}

int main(int argc, char **argv) {
	string p, t;
	while (getline(cin, p)) {
		if (p.size() != 0) {
			int x = p.size();
			t = p;
			reverse(p.begin(), p.end());
			p = p + "~" + t;
			int m = p.size();
			kmpPreprocess(p, m);
			for (int i = b[m - 1] + 1; i < x; i++)
				t += p[i];
			cout << t << endl;
		}
	}
}
