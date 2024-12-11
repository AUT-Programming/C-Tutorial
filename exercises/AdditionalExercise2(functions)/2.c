#include <stdio.h>
#include <stdlib.h>

long long f(int n){
	if(n < 2) return 1;
	return f(n - 1) + f(n - 2);
}

long long F(int n){
	if(n == 0) return 1;
	return f(n) * F(n - 1);
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%Ld\n", F(n));
	return 0;
}
