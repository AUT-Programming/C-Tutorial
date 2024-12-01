#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main() {    
    long long x;
    int ted, n;
    scanf("%lld%d%d", &x, &ted, &n);

    int ans = 0;
    int tedAdi = ted - ((ted + 11) / 12);
    int ghestAdi = (double)x / tedAdi;

    for (int i = 0; i < ted; i++) {
        if (i % 12 == 0)
            ans += (double)x * ((double)n / 100);
        else 
            x -= ghestAdi;
    }

    printf("%d\n", ans);
}