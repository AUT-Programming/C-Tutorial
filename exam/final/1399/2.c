#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

const long long INF = 1e18 + 10;

int *intersection(int *a, int size_a, int *b, int size_b, int *result, int *size_result) {
    (*size_result) = 0;
    for (int i = 0; i < size_a; i++) {
        bool esh = 0;
        for (int j = 0; j < size_b; j++)
            if (a[i] == b[j])
                esh = 1;
        
        if (esh)
            result[(*size_result)++] = a[i];
    }

    return result;
}

int *ejtema(int *a, int size_a, int *b, int size_b, int *eshterak, int *size_eshterak, int *result, int *size_result) {
    for (int i = 0; i < size_a; i++) {
        result[i] = a[i];
        (*size_result)++;
    }

    for (int i = 0; i < size_b; i++) {
        bool esh = 0;
        for (int j = 0; j < (*size_eshterak); j++)
            if (eshterak[j] == b[i])
                esh = 1;

        if (!esh)
            result[(*size_result)++] = b[i];
    }

    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int a[n + 1], b[m + 1];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    int komaki[n];
    int komaki2[n + m];
    int size = 0;
    int size_ans = 0;
    int *ejtemaa = ejtema(a, n, b, m, intersection(a, n, b, m, komaki, &size), &size, komaki2, &size_ans);
    for (int i = 0; i < size_ans; i++)
        printf("%d ", ejtemaa[i]);
    printf("\n");
} 