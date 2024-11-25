#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int a[1000010];
bool sol(int zarfiat, int ind, int tedad_bardashte) {
    if (ind == 0) {
        if (zarfiat == 0 && tedad_bardashte == 0)
            return 1;
        else
            return 0;
    }

    bool ok = 0;
    if (a[ind] <= zarfiat)
        ok = sol(zarfiat - a[ind], ind - 1, tedad_bardashte - 1);
    bool ok1 = sol(zarfiat, ind - 1, tedad_bardashte);

    return (ok || ok1);
}

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 1; i <= m; i++)
        scanf("%d", &a[i]);

    if (sol(n, m, k))
        printf("Yes\n");
    else    
        printf("No\n");
}