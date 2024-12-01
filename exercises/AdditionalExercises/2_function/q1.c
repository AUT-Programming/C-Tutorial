#include <stdio.h>
#include <stdlib.h>

int main() {
	int x;
	scanf("%d", &x);
	if(x < 5 || x > 50){
		printf("-100\n");
		return 0;
	}
	x++;
	long double ans = 0;
	long double a = 0;
	long double b = 1;
	for(int i = 1; i < x; i++){
		if(i%2 == 1){
			a += 2;
		}else{
			b += 2;
		}
		ans += (1.0 * a) / b;
	}
	ans *= 2;
	printf("%Lf\n", ans);
	return 0;
}
