#include <stdio.h>
#include <stdbool.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if (!a || !b || !c) {
        printf("No\n");
    } else if (a + b + c == 180) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    return 0;
}
