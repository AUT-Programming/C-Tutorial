#include <stdio.h>

int main() {
    long long ans, n, k, d, r, g, lst;
    scanf("%Ld %Ld", &n, &k);

    ans = 0;
    lst = 0;
    for (int i = 0; i < n; i++) {
        scanf("%Ld %Ld %Ld", &d, &r, &g);
        ans += d - lst;
        if (r - (ans % (r + g)) > 0) ans += r - (ans % (r + g));
        lst = d;
    }

    ans += k - lst;

    printf("%Ld\n", ans);

    return 0;
}