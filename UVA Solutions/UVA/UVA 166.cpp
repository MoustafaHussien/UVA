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
#include <stdlib.h>
#define oo 99999999
#define ebs 0.000001
using namespace std;
int coins[] = { 5, 10, 20, 50, 100, 200 }, a[500], b[500], num[6];
int change(int money) {
	if (a[money / 5] != -1) {
		return a[money / 5];
	}
	if (money == 0) {
		return a[0] = 0;
	}
	int ans = oo;
	for (int i = 5; i > -1; i--) {
		if (money >= coins[i]) {
			ans = min(ans, change(money - coins[i]) + 1);
		}
	}
	return a[money / 5] = ans;
}

int cash(int money) {
	if (b[money / 5] != -1) {
		return b[money / 5];
	}
	if (money == 0) {
		return b[0] = 0;
	}
	int ans = oo;
	for (int i = 5; i > -1; i--) {
		if (num[i] > 0 && money >= coins[i]) {
			num[i]--;
			ans = min(ans, cash(money - coins[i]) + 1);
			num[i]++;
		}
	}
	return b[money / 5] = ans;
}

int main() {
	memset(a, -1, sizeof(a));
	freopen("input.txt", "r", stdin);
	change(800);
	int sum = 0, x, ans;
	float temp;
	while (scanf("%d %d %d %d %d %d", &num[0], &num[1], &num[2], &num[3],
			&num[4], &num[5])) {
		sum = 0;
		for (int i = 0; i < 6; i++) {
			sum = sum + num[i] * coins[i];
		}
		if (sum == 0) {
			return 0;
		}
		memset(b, -1, sizeof(b));
		scanf("%f", &temp);
		temp += ebs;
		temp = temp * 100;
		x = temp;
		cash(sum);
		ans = oo;
		for (int i = x; i < 600; i = i + 5) {
			memset(b, -1, sizeof(b));
			if (cash(i) > -1 && change(i - x) > -1) {
				ans = min(ans, cash(i) + change(i - x));
			}
		}
		printf("%3d\n", ans);
	}
	return 0;
}
