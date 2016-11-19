//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n;
int main() {
	scanf("%d\n", &n);
	char temp[100];
	string x[n];
	for (int i = 0; i < n; i++) {
		gets(temp);
		x[i] = strtok(temp, " ");
	}
	sort(x, x + n);
	int count = 0;
	int j;
	for (int i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			if (x[i] == x[j]) {
				count++;
			} else {
				break;
			}
		}
		cout << x[i] << " " << count << endl;
		i = i + count-1;
		count = 0;
	}
	return 0;
}
