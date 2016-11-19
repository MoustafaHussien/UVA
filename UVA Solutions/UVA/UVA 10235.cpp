#include <bits/stdc++.h>
using namespace std;
bool isprime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
int getReverse(int num) {
	int new_num = 0;
	while (num > 0) {
		new_num = new_num * 10 + (num % 10);
		num = num / 10;
	}
	return new_num;
}
int main(int argc, char **argv) {
	int num;
//	freopen("input.txt", "r", stdin);
	while (scanf("%d", &num) != EOF) {
		bool a = isprime(num);
		bool b = isprime(getReverse(num));
		if (a && b && (num != getReverse(num))) {
			cout << num << " is emirp.\n";
		} else if (a && b && (num == getReverse(num))) {
			cout << num << " is prime.\n";
		} else if (a && !b) {
			cout << num << " is prime.\n";
		} else {
			cout << num << " is not prime.\n";

		}
	}
	return 0;
}
