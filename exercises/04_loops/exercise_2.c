// ب.م.م و ک.م.م
// بدون تابع

#include <stdio.h>

int main() {
    long long int m, n;
    scanf("%ld %ld", &m, &n);

    // Make sure a and b are positive
    m = (m < 0) ? -m : m;
    n = (n < 0) ? -n : n;

    // Euclidean algorithm (non-recursive): a will be gcd.
    long long int a = m, b = n;
    while (b != 0) {
        const long long int temp = b;
        b = a % b;
        a = temp;
    }

    printf("%ld %ld", a, m * n / a);
    return 0;
}
