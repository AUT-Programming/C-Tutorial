#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int x){
	if(x == 1) return 0;
	for(int i = 2; i <= sqrt(x); i++)
		if(x % i == 0)
			return 0;
	return 1;
}

int main() {
	char ch = ' ';
	int num = 0;
	int ans = 0;
	scanf("%c", &ch);
	while(ch != '\n'){
		if(ch == ' '){
			ans += is_prime(num);
			num = 0;
			scanf("%c", &ch);
			continue;
		}
		num = 10 * num + (ch - '0');
		scanf("%c", &ch);
	}
	ans += is_prime(num);
	printf("%d\n", ans);
	return 0;
}
