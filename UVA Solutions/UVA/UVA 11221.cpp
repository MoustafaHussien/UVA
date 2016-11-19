//============================================================================
// Name        : 11221.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <algorithm>
using namespace std;
string remove(string x) {
	x.erase(std::remove(x.begin(), x.end(), ' '), x.end());
	return x;
}

int main() {
	int test;
	scanf("%d\n", &test);
	string x[test];
	for (int i = 0; i < test; i++) {
		getline(cin, x[i]);
	}
	for (int j = 0; j < test; j++) {
		for (int i = 0, len = x[j].size(); i < len; i++) {
			if (ispunct(x[j][i])) {
				x[j].erase(i--, 1);
				len = x[j].size();
			}
		}
	}
	for (int i = 0; i < test; i++) {
		string temp;
		temp = remove(x[i]);
		int zeft;
		zeft = temp.size();
		char e[zeft];
		strcpy(e, temp.c_str());
		int start = 0;
		int end = strlen(e) - 1;
		while (end > start) {
			if (e[start] != e[end]) {
				break;
			} else {
				start++;
				end--;
			}
		}
		if (end <= start) {
			printf("Case #%d:\n%d\n", i + 1, (int) sqrt(zeft));
		} else {
			printf("Case #%d:\nNo magic :(\n", i + 1);
		}

	}
	return 0;
}

