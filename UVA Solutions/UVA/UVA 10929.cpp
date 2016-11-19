//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
	//(A * B) mod C = (A mod C * B mod C) mod C
	//(A + B) mod C = (A mod C + B mod C) mod C
	while (true) {
		int ans, b = 0;
		string a;
		cin >> a;
		if (a.size() == 1 && a[0] == '0')
			return 0;
		for (int j = 0; j < (int) a.size(); j++) {
			if (j % 2 == 0)
				ans = (a[j] - '0');
			if (j % 2 == 1)
				ans = ((a[j] - '0') * 10) % 11;
			b = (b % 11 + ans % 11) % 11;
		}
		if (b == 0)
			cout << a << " is a multiple of 11.\n";
		else
			cout << a << " is not a multiple of 11.\n";
	}
}
