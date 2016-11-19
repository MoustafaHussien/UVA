//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<iterator>
using namespace std;
int main() {
	int cases;
	scanf("%d", &cases);
	cin.get();
	while (cases--) {
		map<char, int> MP;

		int tot_num;
		cin >> tot_num;
		cin.get();
		while (tot_num--) {

			int cost;
			char ch;
			scanf("%c %d", &ch, &cost);
			cin.get();
			MP[ch] = cost;
		}
		int line, count;
		count = 0;
		scanf("%d\n", &line);
		char ch;
		unsigned long long int sum = 0;
		for (;;) {
			scanf("%c", &ch);
			sum += MP[ch];
			if (ch == '\n') {
				count++;
				if (count == line)
					break;
			}
		}
		printf("%.2lf$\n", (double) sum / 100.0);

	}
	return 0;
}
