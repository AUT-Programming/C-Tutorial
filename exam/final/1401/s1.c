#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
	int y, m, d;
} date;

date new_date (char *s) {
	date d;
	sscanf(s, "%d", &(d.y));
	sscanf(s + 5, "%d", &(d.m));
	sscanf(s + 8, "%d", &(d.d));
	return d;
}

bool cmp (date x, date y) { // check x < y
	if (x.y != y.y) return x.y < y.y;
	if (x.m != y.m) return x.m < y.m;
	return x.d < y.d;
}

void swap (date *x, date *y) { date tmp = *x; *x = *y; *y = tmp; }

void print (date d) { printf("%04d-%02d-%02d\n", d.y, d.m, d.d); }

int convert (date d) { // convert date to int
	int res = d.y * 366 + d.d;
	if (d.m > 6) res += 31 * 6 + (d.m - 6) * 30;
	else res += 31 * d.m;
	return res;
}

struct list {
	date d;
	struct list *nxt, *prv;
};

typedef struct list List;

void add (List *L, char *s) {
	L->d = new_date(s);
	L->nxt = (List*)calloc(1, sizeof(List));
	L->nxt->prv = L;
}

void sort (List *L, int n) { // bubble sort
	for (int i = 0; i < n; i++)
		for (List *p = L; p->nxt != NULL; p = p->nxt)
			if (!cmp(p->d, p->nxt->d))
				swap(&(p->d), &(p->nxt->d));
}

List* advance (List *it, int n) {
	for (; n > 0; n--) it = it->nxt;
	for (; n < 0; n++) it = it->prv;
	return it;
}

void find_median (List *mylist, int n) {
	print(advance(mylist, n / 2)->d);
}

void find_mode (List *mylist, int n) {
	int mx = 1; date d = mylist->d;
	for (List *l = mylist, *r = mylist; r->nxt != NULL; l = r->nxt) {
		int x = 1;
		for (r = l; r->nxt != NULL && !cmp(l->d, r->nxt->d) && !cmp(r->nxt->d, l->d); r = r->nxt) x++;
		if (mx < x) {
			mx = x;
			d = l->d;
		}
	}
	print(d);
}

double Abs (double x) {
	if (x < 0) x *= -1;
	return x;
}

void find_center (List *mylist, int n) {
	double sum = 0;
	for (List *p = mylist; p != NULL; p = p->nxt) sum += convert(p->d);
	double avg = sum / n;
	double mn = __builtin_inf(); date res = mylist->d;
	for (List *p = mylist; p != NULL; p = p->nxt) if (mn > Abs(avg - convert(p->d)))
		mn = Abs(avg - convert(p->d)), res = p->d;
	print(res);
}

void Exit (List *L) { // free all allocated memories
	List *p;
	while (L != NULL) {
		p = L->nxt;
		free(L);
		L = p;
	}
	exit(0);
}

int main ()
{
	int n, type;
	List *mylist = (List*)calloc(1, sizeof(List)), *cur;
	
	for (n = 0, cur = mylist; ; n++, cur = cur->nxt) {
		char input [20];
		scanf(" %s", input);
		if (input[0] == 'M') { type = strlen(input); break; }
		add(cur, input);
	}
	cur->prv->nxt = NULL; free(cur);

	sort(mylist, n);

	find_median(mylist, n);
	if (type == 1) Exit(mylist);
	
	find_mode(mylist, n);
	if (type == 2) Exit(mylist);
	
	find_center(mylist, n);
	Exit(mylist);
}
/*
1401-12-27
1400-05-09
1401-07-03
1400-01-21
1400-08-15
1401-06-06
1400-07-16
1400-10-14
1401-06-06
1400-04-16
1400-07-19
1401-06-06
1400-12-02
1401-12-18
1401-06-06
1400-11-25
1400-11-13
1401-03-28
1400-05-05
M

1400-04-27
1401-03-21
1401-05-27
1401-11-22
1400-09-21
1401-07-21
1401-08-06
1400-05-09
1400-09-21
1400-04-02
1400-10-07
1400-09-21
1400-07-04
1400-06-24
1400-03-26
1400-09-04
1400-04-04
1401-08-19
1400-09-21
1401-07-13
1401-10-27
1401-01-15
1400-05-25
1401-08-08
1400-08-20
MMM

*/