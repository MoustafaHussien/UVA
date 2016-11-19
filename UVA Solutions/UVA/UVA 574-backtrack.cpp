//============================================================================
// Name        : UVA.cpp
// Author      : moustafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;
int t, n;
int num[12];
bool print[12];
map<string,int> m;
void backtrack(int index, int sum) {

	sum += num[index];
	print[index] = true;
//	printf("%d %d %d\n",index,sum,num[index]);
	if(sum == t) {
		string s = "";
		for(int i =  0 ; i < n; i++) {
			if(print[i])
				s = s + itoa(num[i]);
		}
		printf("\n");

		print[index] = false;
		return ;
	}


	if(sum > t) {
		print[index] = false;
		return;
	}
//	printf("%d  %d trying\n",index,sum);
	for(int i = index + 1; i < n; i++) {
		backtrack(i,sum);
	}
	print[index] = false;

}




int main() {
	scanf("%d %d", &t, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	for(int i = 0; i < n; i++){
//		printf("%d %d %d lll\n",i,num[i],n);s
		backtrack(i,0);
	}
	return 0;
}






