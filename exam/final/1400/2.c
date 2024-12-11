#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

const int INF = 2e9;

int a[100000];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int sz = 0;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            if (sum == k) {
                if (j - i + 1 > sz) {
                    sz = j - i + 1;
                    l = i;
                    r = j;
                }
            }
        }
    }

    for (int i = l; i <= r; i++)
        printf("%d ", a[i]);
    printf("\n");
} 