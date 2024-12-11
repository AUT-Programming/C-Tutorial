#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int f(int n, int m, int x){
	if(n == 0 && m == 0) return 1 - x;
	if(n < 0 || m < 0) return -1;
	if(f(n - 1, m, 1 - x) == x) return x;
	if(f(n - 2, m, 1 - x) == x) return x;
	if(f(n, m - 1, 1 - x) == x) return x;
	if(f(n, m - 2, 1 - x) == x) return x;
	return 1 - x;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int ans = f(n, m, 0);
	if(ans == 0) printf("Fayaz\n");
	else printf("Armin");
	return 0;
}
