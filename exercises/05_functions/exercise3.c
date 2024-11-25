// ب.م.م
#include<stdio.h>

long unsigned int GCD(long unsigned int a, long unsigned int b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

int main() {
    long unsigned int a, b;
    scanf("%lu%lu", &a, &b);
    printf("%lu", GCD(a, b));
}
