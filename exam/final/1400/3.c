#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

const int INF = 2e9;

struct lst {
    char c;
    struct lst *next;
};

void add(char t, struct lst *head) {
    struct lst *x = head;
    while (x->next != NULL) {
        x = x->next;

        if (x->c == t)
            return;
    }

    struct lst *new = malloc(sizeof(struct lst));
    new->c = t;
    new->next = NULL;
    x->next = new;
}

int size(struct lst *head) {
    struct lst *x = head;
    int res = 0;
    while (x->next != NULL)
        x = x->next, res++;
    return res;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char s[110];
    for (int i = 0; i < n; i++) {
        scanf("%s", s);

        int m = strlen(s);
        struct lst *head = malloc(sizeof(struct lst));
        head->next = NULL; 
        for (int j = 0; j < m; j++) {
            add(s[j], head);
        }

        if (size(head) == k)
            printf("%s\n", s);
    }
} 