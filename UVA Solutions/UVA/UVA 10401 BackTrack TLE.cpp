//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;
bool visits[10][10];
int dx[] = { 0, 0, 0, 1, 1, 1, -1, -1, -1 };
int dy[] = { 0, 1, -1, 0, 1, -1, 0, 1, -1 };
int sol = 0;
bool check(int x, int y) {
	for (int i = 0; i < 9; i++) {
		if (x + dx[i] > -1 && x + dx[i] < 10 && y + dy[i] > -1
				&& y + dy[i] < 10) {
			if (visits[x + dx[i]][y + dy[i]] == true) {
				return false;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		if (visits[i][y] == true) {
			return false;
		}
	}
	return true;
}
void print() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (visits[i][j] == true) {
				cout << "1";
			} else {
				cout << "0";
			}
		}
		cout << endl;
	}

}
void solve(int col) {
	if (col == 10) {
		sol++;
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (check(i, col) == true) {
			visits[i][col] = true;
			solve(col + 1);
			visits[i][col] = false;
		}
	}
}

int main() {
	memset(visits, false, sizeof visits);
	solve(0);
	cout << sol;
	return 0;
}
