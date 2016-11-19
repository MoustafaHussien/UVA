//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <sstream>

using namespace std;

bool compint(int x, int y) {
	return x > y;
}
int main() {
	int t, n;
	bool a7a = true;
	while (1) {
		scanf("%d", &t);
		scanf("%d", &n);
		if (t == 0 && n == 0) {
			return 0;
		}
		string zeft[1000];
		int zeftcount = 0;
		int a[n];
		int b[n];
		for (int j = 0; j < n; j++) {
			b[j] = 0;
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		if (n == 1) {
			if (a[0] == t) {
				zeftcount = 1;
				ostringstream w;
				w << "" << t;
				zeft[0] = w.str();
			}
		} else {
			//--------------------------------------------------------
			for (int i = 0; i <= n; i++) {
				for (int j = 0; j < i; j++) {
					b[j] = 1;
				}
				do {
					ostringstream x;
					int sum = 0;
					bool v = true;
					for (int j = 0; j < n; j++) {
						if (b[j] == 1) {
							sum = sum + a[j];
							if (sum > t) {
								sum = 0;
								break;
							}
							if (v == true) {
								v = false;
								x << "" << a[j];
							} else {

								x << "+" << a[j];
							}
						}
					}
					if (sum == t) {
						bool zeften = true;
						for (int i = 0; i < zeftcount; i++) {
							if (zeft[i] == x.str()) {
								zeften = false;
								break;
							}
						}
						if (zeften) {
							zeft[zeftcount] = x.str();
							zeftcount++;
						}
					}

				} while (next_permutation(b, b + n, compint));
			}
			//--------------------------------------------------------
		}
		if (a7a) {
			printf("\n");
			a7a = false;
		}
		if (zeftcount == 0) {
			printf("Sums of %d:\nNONE\n", t);
		} else {
			printf("Sums of %d:\n", t);
			for (int i = 0; i < zeftcount; i++) {
				cout << zeft[i] << endl;
			}
		}
	}
	return 0;
}
