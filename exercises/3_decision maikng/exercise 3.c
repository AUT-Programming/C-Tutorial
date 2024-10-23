#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if (a * a + b * b == c * c || c * c + a * a == b * b || b * b + c * c == a * a) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    return 0;
}
