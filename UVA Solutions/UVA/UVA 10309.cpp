//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <stdlib.h>
using namespace std;

bool lights[10][10];
bool test[10][10];
int reversei[5] = { 0, 0, 0, 1, -1 };
int reversej[5] = { 0, 1, -1, 0, 0 };
//-----------------------------------------------
void reverse(int i, int j) {
	int x, y;
	for (int k = 0; k < 5; k++) {
		x = i + reversei[k];
		y = j + reversej[k];
		if (x >= 0 && x < 10 && y >= 0 && y < 10) {
			test[x][y] = !test[x][y];
		}
	}
}
//----------------------------------------------------
int main() {
	while (true) {
		char x[100];
		scanf("%s", x);
		if (strcmp(x, "end") == 0) {
			return 0;
		}
		char row[10];
		for (int i = 0; i < 10; i++) {
			scanf("%s", row);
			for (int j = 0; j < 10; ++j) {
				if (row[j] == '#') {
					lights[i][j] = false;
					test[i][j] = false;
				} else {
					lights[i][j] = true;
					test[i][j] = true;
				}
			}
		}

		int min = 10000;
		for (int i = 0; i < pow(2, 10); i++) {
			int count = 0;
			int markcount = 0;
			bool mark[10];
			for (int k = 9; k >= 0; k--) {
				if ((i & (1 << k)) != 0) {
					mark[markcount] = true;
					markcount++;
				} else {
					mark[markcount] = false;
					markcount++;
				}
			}
			//-----------------------------------
			for (int j = 0; j < 10; j++) {
				if (mark[j]) {
					reverse(0, j);
					count++;
				}
			}
			//--------------------------------------
			for (int i = 1; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (test[i - 1][j]) {
						reverse(i, j);
						count++;
					}
				}
			}
			//------------------------------------
			bool flag = true;
			for (int j = 0; j < 10; j++) {
				if (test[9][j]) {
					flag = false;
					break;
				}
			}
			//------------------------------------
			if (flag && count < min) {
				min = count;
			} else {
				memcpy(test, lights, sizeof(bool) * 100);
			}
		}
		cout << x;
		if (min > 100) {
			printf(" -1\n");
		} else {
			printf(" %d\n", min);
		}
	}
	return 0;
}
