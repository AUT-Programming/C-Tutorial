#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
	char str[200];
	scanf("%s", str);
	int n;
	scanf("%d", &n);
	int ans = 0;
	for(int i = 1; i <= n; i++){
		char STR[200];
		scanf("%s", STR);
		int n1 = strlen(str);
		int n2 = strlen(STR);
		if(n1 == n2){
			bool ok = 1;
			for(int j = 0; j < n1; j++)
				if(str[j] != STR[j])
					ok = 0;
			if(ok)
				ans++;
		}
		if(n1 - 1 == n2){
			for(int j = 0; j < n1; j++){
				bool ok = 1;
				for(int k = 0; k < n1; k++){
					if(k == j)
						continue;
					if(k > j){
						if(str[k] != STR[k - 1])
							ok = 0;
					}else{
						if(str[k] != STR[k])
							ok = 0;
					}
				}
				if(ok){
					ans++;
					break;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
