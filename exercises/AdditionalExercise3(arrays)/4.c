#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char str[100000];

bool is_number(char ch){
	int x = ch - '0';
	return (x >= 0 && x <= 9);
}

bool is_small_alphabet(char ch){
	int x = ch - 'a';
	return (x >= 0 && x <= 25);
}

bool is_big_alphabet(char ch){
	int x = ch - 'A';
	return (x >= 0 && x <= 25);
}

bool is_alphabet(char ch){
	return (is_small_alphabet(ch) || is_big_alphabet(ch));
}

bool is_dot(char ch){
	return (ch == '.');
}

bool is_underline(char ch){
	return (ch == '_');
}

bool is_dash(char ch){
	return (ch == '-');
}

bool is_underline_dot_dash(char ch){
	return (is_underline(ch) || is_dot(ch) || is_dash(ch));
}

bool is_ok_part1(int l, int r){
	if(is_number(str[l]))
		return 0;
	for(int i = l; i <= r; i++)
		if(!(is_underline(str[i]) || is_alphabet(str[i]) || is_dot(str[i]) || is_number(str[i])))
			return 0;
	if(is_underline_dot_dash(str[l]))
		return 0;
	for(int i = l + 1; i <= r; i++)
		if(is_underline_dot_dash(str[i]) && is_underline_dot_dash(str[i - 1]))
			return 0;
	return 1;
} 

bool is_ok_part2(int l, int r){
	int cnt = 0;
	for(int i = l; i <= r; i++)
		if(is_dot(str[i]))
			cnt++;
	if(cnt == 0)
		return 0;
	for(int i = l; i <= r; i++)
		if(!(is_underline(str[i]) || is_small_alphabet(str[i]) || is_dot(str[i]) || is_dash(str[i])))
			return 0;
	for(int i = l + 1; i <= r; i++)
		if(is_underline_dot_dash(str[i]) && is_underline_dot_dash(str[i - 1]))
			return 0;
	if(is_underline_dot_dash(str[l]))
		return 0;
	return 1;
}

int main() {
	scanf("%s", str);
	int i = 0;
	int n = strlen(str);
	while(i < n && str[i] != '@')
		i++;
	if(i == n || i == 0 || i == n - 1){
		printf("No\n");
		return 0;
	}
	if(is_ok_part1(0, i - 1) && is_ok_part2(i + 1, n - 1)){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	return 0;
}
