#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n, T;
int Ai[10];
int ti[10];
int pi[10];
int is[10];
long double ans;

long double VAL(int i, int num, int tt, long double pos){
	if(tt > T) return 0;
	if(i > n){
		if(num < 10) return 0;
		return pos;
	}
	if(is[i] == 0) return VAL(i + 1, num, tt, pos);
	return VAL(i + 1, num, tt + ti[i], 1.0 * pos * (1.0 * (100 - pi[i]) / 100)) + VAL(i + 1, num + Ai[i], tt + ti[i], 1.0 * pos * (1.0 * pi[i] / 100));
}

void f(int i){
	if(i > n){
		long double x = VAL(1, 0, 0, 1);
		if(x > ans) ans = x;
		return;
	}
	is[i] = 1;
	f(i + 1);
	is[i] = 0;
	f(i + 1);
}

int main() {
	scanf("%d%d", &n, &T);
	for(int i = 1; i <= n; i++){
		scanf("%d", &Ai[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &ti[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &pi[i]);
	}
	f(1);
	printf("%.6Lf\n", ans);
	return 0;
}
