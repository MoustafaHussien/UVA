//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;
long long unsigned ans[1000001];

int main() {
	ans[0] = ans[1] = ans[2] = ans[3] = 0;
	long long unsigned inc = 0;
	int N;
	for (int i = 4; i < 1000001; i++) {
		inc += (i - 2) / 2;
		ans[i] = ans[i - 1] + inc;
	}
	while (scanf("%d", &N) && N >= 3) {
		printf("%lld\n", ans[N]);
	}
}
