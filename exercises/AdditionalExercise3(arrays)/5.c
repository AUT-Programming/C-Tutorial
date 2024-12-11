#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char str[300];
double num[300];
long long NUM[300];
int pair[300];
bool is[300];

bool is_number(char ch){
	int x = ch - '0';
	return (x >= 0 && x <= 9);
}

double GET(int i){
	char *end;
	return strtod(&str[i], &end);
}

double calculate(){
	for(int i = 1; i < 300; i++)
		if(is_number(str[i]) && !is_number(str[i - 1]) && str[i - 1] != '.'){
			num[i] = GET(i);
			is[i] = 1;
		}
	int arr[300] = {};
	int arr_sz = 0;
	for(int i = 0; i < 300; i++){
		if(str[i] == '(')
			arr[arr_sz++] = i;
		else if(str[i] == ')'){
			pair[arr[--arr_sz]] = i;
		}
	}
	for(int i = 299; i >= 0; i--)
		if(str[i] == '('){
			char op = ' ';
			int pnum = i;
			for(int j = i + 1; j <= pair[i]; j++){
				if(is[j] == 1){
					if(op == '*' || op == '/'){
						if(op == '*')
							num[pnum] = num[pnum] * num[j];
						else
							num[pnum] =  num[pnum] / num[j];
						is[j] = 0;
					}else{ 
						pnum = j;
					}
				}else{
					if(str[j] == '*' || str[j] == '/' || str[j] == '+' || str[j] == '-')
						op = str[j];
				}
				if(str[j] == '(')
					j = pair[j];
			}
			is[i] = 1;
			op = '+';
			for(int j = i + 1; j <= pair[i]; j++){
				if(is[j] == 1){
					if(op == '+')
						num[i] += num[j];
					else 
						num[i] -= num[j];
					is[j] = 0;
				}else{
					if(str[j] == '+' || str[j] == '-')
						op = str[j];
				}
				if(str[j] == '(')
					j = pair[j];
			}
		}
	return num[0];
}

int main() {
	gets(str);
	for(int i = 298; i > 0; i--)
		str[i] = str[i - 1];
	str[0] = '(';
	str[299] = ')';
	char STR[50];
	double ans = calculate();
	sprintf(STR, "%.8lf", ans);
	int n =strlen(STR);
	int cnt = 0;
	for(int i = 0; i < n; i++)
		if(STR[i] == '.')
			cnt++;
	if(cnt > 0){
		while(STR[n - 1] == '0')
			n--;
		if(STR[n - 1] == '.')
			n--;
	}
	for(int i = 0; i < n; i++)
		printf("%c", STR[i]);
	printf("\n");
	return 0;
}

