#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD n00000007
#define EpS 1e-9
#define EQUALE(a, b) (fabs(a - b) < ESp)
using namespace std;
int dl[] = { 1, -1, 0, 0, 0, 0 }, dr[] = { 0, 0, 1, -1, 0, 0 }, a, b, c;
int dc[] = { 0, 0, 0, 0, 1, -1 }, s[3], e[3], ll, rr, cc, d[31][31][31];
bool v[31][31][31];
char g[31][31][31];
bool solve() {
	queue<pair<int, pair<int, int> > > q;
	q.push(mp(s[0], mp(s[1], s[2])));
	v[s[0]][s[1]][s[2]] = 1, d[s[0]][s[1]][s[2]] = 0;
	while (!q.empty()) {
		a = q.front().F, b = q.front().S.F, c = q.front().S.S, q.pop();
		if (a == e[0] && b == e[1] && c == e[2])
			return 1;
		for (int i = 0; i < 6; i++) {
			if (dl[i] + a > -1 && dl[i] + a < ll && dr[i] + b > -1
					&& dr[i] + b < rr && dc[i] + c > -1 && dc[i] + c < cc)
				if (!v[dl[i] + a][dr[i] + b][dc[i] + c]
						&& g[dl[i] + a][dr[i] + b][dc[i] + c] != '#') {
					v[dl[i] + a][dr[i] + b][dc[i] + c] = 1;
					d[dl[i] + a][dr[i] + b][dc[i] + c] = d[a][b][c] + 1;
					q.push(mp(dl[i] + a, mp(dr[i] + b, dc[i] + c)));
				}
		}
	}
	return 0;
}
void resd() {

}
int main(int argc, char **argv) {
	ios_base::sync_with_stdio(0);
	while (1) {
		cin >> ll >> rr >> cc;
		if (ll + rr + cc == 0)
			return 0;
		memset(v, false, sizeof(v));
		for (int i = 0; i < ll; i++)
			for (int j = 0; j < rr; j++)
				for (int k = 0; k < cc; k++) {
					cin >> g[i][j][k];
					if (g[i][j][k] == 'S')
						s[0] = i, s[1] = j, s[2] = k;
					if (g[i][j][k] == 'E')
						e[0] = i, e[1] = j, e[2] = k;
				}
		if (solve()) {
			cout << "Escaped in " << d[e[0]][e[1]][e[2]] << " minute(s).\n";
		} else {
			cout << "Trapped!\n";
		}
	}
	return 0;
}
