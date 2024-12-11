#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

const long long INF = 1e18 + 10;

int a[100100];

int abs(int x) {
    if (x < 0)
        return -x;
    return x;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
        scanf("%d", &a[i]);

    long long ans = INF;
    int ind = -1;
    for (int i = 0; i < n; i++) {
        long long res = 0;
        for (int j = 0; j < n; j++)
            res += abs(i - j) * a[j];
        
        if (res < ans) {
            ind = i;
            ans = res;
        }
    }

    printf("%d\n", ind + 1);
}