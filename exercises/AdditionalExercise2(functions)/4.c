#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n;
int ans[13];

void f(int i){
	if(i > n){
		for(int j = 1; j <= n; j++){
			if(ans[j] == 1) printf("R");
			else if(ans[j] == 2) printf("B");
			else if(ans[j] == 3) printf("W");
		}
		printf("\n");
		return;
	}
	ans[i] = 1;
	f(i + 1);
	if(ans[i - 1] != 3){
		ans[i] = 2;
		f(i + 1);
	}
	if(ans[i - 1] != 2){
		ans[i] = 3;
		f(i + 1);
	}
}

int main() {
	scanf("%d", &n);
	f(1);
	return 0;
}
