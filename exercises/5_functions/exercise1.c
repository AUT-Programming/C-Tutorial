#include <stdio.h>
#include <stdbool.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    for (int i = a; i <= b; i++) {
        bool isPrime = true;
        
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime && i != 1) {
            printf("%d\n", i);
        }
    }

    return 0;
}
