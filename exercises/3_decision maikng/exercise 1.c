#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    if (T > 100) {
        printf("Steam\n");
    } else if (T < 0) {
        printf("Ice\n");
    } else {
        printf("Water\n");
    }

    return 0;
}