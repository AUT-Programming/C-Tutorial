#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int token[256];
char s[5000 + 4];
char s2[5000 + 4];

int is_number(char ch){
	int x = ch - '0';
	if(x < 0 || x > 9)
		return 0;
	return 1;
}

void make(int x){
	token[x] = 1;
}

void init(){
	make(' ');
	make('"');
	char str[] = ".?!,;:%()-";
	for(int i = 0; i < 10; i++)
		make(str[i]);	
}

int main() {
	init();
	fgets(s, 5000 + 4, stdin);
	int n = strlen(s);
	int ptr = 0;
	while(1){
		if(ptr == n)
			break;
		if(is_number(s[ptr])){
			while(is_number(s[ptr]))
				ptr++;
			if(s[ptr] == '.' && is_number(s[ptr + 1])){
				ptr++;
				while(is_number(s[ptr]))
					ptr++;
				printf("FLOAT");
			}else {
				printf("INT");
			}
		}else if(token[s[ptr]]){
			printf("%c", s[ptr++]);
		}else{
			int ptr2 = 0;
			for(; ptr < n && (token[s[ptr]] == 0 || s[ptr] == '-'); s2[ptr2++] = s[ptr], ptr++);
			char http[5] = "http";
			char str1[5];
			for(int i = 0; i < 4; i++) str1[i] = s2[i];
			str1[4] = '\0';
			if(ptr2 >= 4 && strcmp(http, str1) == 0){
				for(; ptr < n && s[ptr] != ' ' && s[ptr] != '(' && s[ptr] != ')' && s[ptr] != ' '; ptr++);
				printf("LINK");
			}else{
				s2[ptr2] = '\0';
				printf("%s", s2);
			}
		}
		if(s[ptr] != ' ' && s[ptr - 1] != ' ')
			printf(" ");
	}
	printf("\n");
	return 0;
}


