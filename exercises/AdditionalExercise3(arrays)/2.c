#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int num1[300], num2[300], ans[300];
int A[10][10];
bool neg1, neg2;

int main() {
	for(int i = 1; i <= 9; i++)
		for(int j = 1; j <= 9; j++)
			scanf("%d", &A[i][j]);
	char str1[200], str2[200];
	scanf("%s%s", str1, str2);
	int n1 = strlen(str1);
	int ind = 0;
	while(n1 > 0){
		n1--;
		if(str1[n1] == '-'){
			neg1 = 1;
			break;
		}
		if(str1[n1] == '+')
			break;
		num1[ind++] = str1[n1] - '0'; 
	}
	int n2 = strlen(str2);
	ind = 0;
	while(n2 > 0){
		n2--;
		if(str2[n2] == '-'){
			neg2 = 1;
			break;
		}
		if(str2[n2] == '+')
			break;
		num2[ind++] = str2[n2] - '0';
	}
	for(int i = 0; i < 104; i++)
		for(int j = 0; j < 104; j++){
			if(num1[i] == 0 || num2[j] == 0){
				continue;
			}
			ans[i + j] += A[num1[i]][num2[j]];
		}
	for(int i = 0; i < 210; i++){
		ans[i + 1] += ans[i] / 10;
		ans[i] %= 10;
	}
	if(neg2 ^ neg1)
		printf("-");
	int N = 299;
	while(ans[N] == 0)
		N--;
	for(int i = N; i >= 0; i--){
		printf("%d", ans[i]);
	}
	printf("\n");
			
	return 0;
}
