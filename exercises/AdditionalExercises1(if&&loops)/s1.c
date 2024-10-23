#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if (b * b == 4 * a * c && b * a > 0) {
        printf("1\n");
    } else if (b * b == 4 * a * c && b * a < 0) {
        printf("2\n");
    } else if (b == 0 && a * c < 0) {
        printf("3\n");
    } else {
        printf("None\n");
    }

    return 0;
}
