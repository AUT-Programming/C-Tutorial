#include <stdio.h>
#include <stdlib.h>

struct node{
	char ch;
	struct node* next;
	struct node* prev;
};

struct node* st;
struct node* en;

struct node* create(char ch){
	struct node* rt = (struct node*) malloc(1 * sizeof(struct node));
	if(rt == NULL)
		exit(-1);
	rt->ch = ch;
	rt->next = NULL;
	rt->prev = NULL;
	return rt;
}

void erase(struct node* x){
	x->prev->next = x->next;
	x->next->prev = x->prev;
	free(x);
}

void add(struct node* x, struct node* CUR){
	x->next = CUR;
	x->prev = CUR->prev;
	CUR->prev->next = x;
	CUR->prev = x;
}

void replace(char a, char b){
	struct node* CUR = st->next;
	while(CUR->next != NULL){
		if(CUR->ch == a)
			CUR->ch = b;
		CUR = CUR->next;
	}
}

void PRINT(){
	struct node* CUR = st->next;
	while(CUR->next != NULL){
		printf("%c", CUR->ch);
		CUR = CUR->next;
	}
	printf("\n");
}

void FREE(){
	struct node* CUR = st;
	while(CUR->next != NULL){
		struct node* x = CUR;
		CUR = CUR->next;
		free(x);
	}
	free(CUR);
}

int main() {
	st = create('#');
	en = create('#');
	st->next = en;
	en->prev = st;
	struct node* CUR = en;
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		char id;
		scanf(" %c", &id);
		if(id == 'L'){
			if(CUR->prev->prev != NULL)
				CUR = CUR->prev;
		}else if(id == 'R'){
			if(CUR->next != NULL)
				CUR = CUR->next;
		}else if(id == 'D'){
			if(CUR->prev->prev != NULL)
				erase(CUR->prev);
		}else if(id == 'I'){
			char ch;
			scanf(" %c", &ch);
			add(create(ch), CUR);
		}else if(id == 'C'){
			char S, T;
			scanf(" %c %c", &S, &T);
			replace(S, T);
		}
	}
	PRINT();
	FREE();
	return 0;
}
