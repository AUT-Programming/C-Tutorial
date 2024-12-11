#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node* next;
	double x;
};

struct node* lnk_list;

struct node* create_node(double x){
	struct node* rt = (struct node*) malloc(1 * sizeof(struct node));
	if(rt == NULL)
		return NULL;
	rt->x = x;
	rt->next = NULL;
	return rt;
}

void add_to_end(struct node* nd){
	struct node* CUR = lnk_list;
	for(; CUR->next != NULL; CUR = CUR->next);
	CUR->next = nd;
}

double SUM(){
	double rt = 0;
	struct node* CUR = lnk_list;
	for(; CUR->next != NULL; CUR = CUR->next, rt += CUR->x);
	return rt;
}

int SIZE(){
	int rt = 0;
	struct node* CUR = lnk_list;
	for(; CUR->next != NULL; CUR = CUR->next, rt++);
	return rt;
}

struct node* SELECT(int n){
	if(SIZE() < n)
		return NULL;
	struct node* CUR = lnk_list;
	for(int i = 1; i <= n; i++){
		CUR = CUR->next;
	}
	return CUR;
}

void erase(int n){
	if(SIZE() < n)
		return;
	struct node* CUR = SELECT(n - 1);
	struct node* NXT = CUR->next;
	CUR->next = NXT->next;
	free(NXT);
}

void FREE(){
	struct node* CUR = lnk_list;
	for(struct node* x; CUR->next != NULL; x = CUR, CUR = CUR->next, free(x));
	free(CUR);
}

int main() {
	lnk_list = create_node(0);
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		double x;
		scanf("%lf", &x);
		add_to_end(create_node(x));
	}
	int mid = n / 2 + 1;
	printf("%.5lf\n", SELECT(mid)->x);
	erase(mid);
	double ans = 1.0 * SUM() / SIZE();
	printf("%.5lf\n", ans);
	FREE();
	return 0;
}
