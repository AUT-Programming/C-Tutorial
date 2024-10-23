#include <stdio.h>
#include <math.h>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int in[n];
    scanf("%d", &in[0]);
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
        in[i] *= i + 1;
    }
    while (q--) {
        int t;
        scanf("%d", &t);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long pw = 1;
            for (int j = 0; j < i; j++) pw *= t;
            ans += pw * in[i];
        }
        printf("%Ld ", ans);
    }
    return 0;
}