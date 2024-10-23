#include <stdio.h>

#define MAX_N 100000

int main() {
    int n1, n2;
    scanf("%d", &n1);

    int a1[n1];
    for (int i = 0; i < n1; i++) {
        scanf("%d", &a1[i]);
    }

    scanf("%d", &n2);
    int a2[n2];
    for (int i = 0; i < n2; i++) {
        scanf("%d", &a2[i]);
    }

    for (int i = 1; i < n1; i++) {
        if (a1[i] < a1[i - 1]) {
            printf("Not sorted\n");
            return 0;
        }
    }

    for (int i = 1; i < n2; i++) {
        if (a2[i] < a2[i - 1]) {
            printf("Not sorted\n");
            return 0;
        }
    }

    int a3[n1 + n2];
    for (int i = 0; i < n1; i++) {
        a3[i] = a1[i];
    }

    for (int i = n1; i < n1 + n2; i++) {
        a3[i] = a2[i - n1];
    }

    int p1 = 0, p2 = 0;
    int tmp[n1 + n2];

    while (p1 < n1 && p2 < n2) {
        if (a1[p1] < a2[p2]) {
            tmp[p1 + p2] = a1[p1];
            p1++;
        } else {
            tmp[p1 + p2] = a2[p2];
            p2++;
        }
    }

    while (p1 < n1) {
        tmp[p1 + p2] = a1[p1];
        p1++;
    }

    while (p2 < n2) {
        tmp[p1 + p2] = a2[p2];
        p2++;
    }

    for (int i = 0; i < n1 + n2; i++) {
        a3[i] = tmp[i];
    }

    for (int i = 0; i < n1 + n2; i++) {
        printf("%d\n", a3[i]);
    }

    return 0;
}
