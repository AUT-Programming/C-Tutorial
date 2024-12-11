#include <stdio.h>
#include <stdlib.h>

struct node{
	int x;
	struct node* next, *prev;
};
int n;
struct node* st;
struct node* en;

struct node* create(int x){
	struct node* rt = (struct node*) malloc(1 * sizeof(struct node));
	if(rt == NULL)
		exit(-1);
	rt->x = x;
	rt->next = NULL;
	rt->prev = NULL;
	return rt;
}

void swap(struct node* a, struct node* b){
	b->prev = a->prev;
	a->next = b->next;
	b->next = a;
	a->prev = b;
	b->prev->next = b;
	a->next->prev = a;
}

void erase(struct node* nd){
	struct node* a = nd->prev;
	struct node* b = nd->next;
	a->next = b;
	b->prev = a;
	free(nd);
}

void add_end(struct node* nd){
	struct node* a = en->prev;
	a->next = nd;
	en->prev = nd;
	nd->next = en;
	nd->prev = a;
}

void PRINT(){
	struct node* CUR = en->prev;
	while(CUR->prev != NULL){
		printf("%d\n", CUR->x);
		CUR = CUR->prev;
	}
}

void SORT(){
	for(int j = 1; j <= n; j++){
		struct node* CUR = st->next;
		for(int i = 1; i <= n - 1; i++){
			if(CUR->x < CUR->next->x)
				swap(CUR, CUR->next);
			else
				CUR = CUR->next;
		}
	}
}

void UNIQUE(){
	struct node* CUR = st->next;
	while(1){
		if(CUR->next == NULL)
			return;
		if(CUR->next->next == NULL)
			return;
		if(CUR->x == CUR->next->x)
			erase(CUR->next);
		else
			CUR = CUR->next;
	}
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
	st = create(0);
	en = create(0);
	st->next = en;
	en->prev = st;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		add_end(create(x));
	}
	SORT();
	UNIQUE();
	PRINT();
	FREE();
	return 0;
}
