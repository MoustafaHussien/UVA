#include<iostream>
#include<cstdlib>
#include<cmath>
#include <stdio.h>
using namespace std;

int n;
struct sprinkler {
	double start;
	double end;
};

int cmp(struct sprinkler* p, struct sprinkler *q) {
	return p->start - q->start;
}

int main() {
	int m, l, w;
	while (scanf("%d %d %d", &n, &l, &w) == 3) {
		sprinkler a[n];
		float r, x;
		m = 0;
		for (int i = 0; i < n; i++) {
			scanf("%f %f", &x, &r);
			double d = r * r - 0.25 * w * w;
			if (d <= 0)
				continue;
			d = sqrt(d);
			a[m].start = x - d;
			a[m].end = x + d;
			m++;
		}
		qsort(a, m, sizeof(a[0]), (int (*)(const void*, const void*))cmp);double
		left = 0;
		double right = 0;
		int cnt = 1;
		int i;
		for (i = 0; i < m; i++) {
			if (a[i].start <= left) {
				right = max(right, a[i].end);
			} else {
				if (right < a[i].start)
					break;
				left = right;
				cnt++;
				i--;
			}
		}
		if (right >= l)
			cout << cnt << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}
