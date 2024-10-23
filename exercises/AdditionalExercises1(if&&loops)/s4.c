#include <stdio.h>

const int MIN = -1e9;

int main() {
    int n;
    scanf("%d", &n);

    int a1 = MIN, a2 = MIN, a3 = MIN, in;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &in);

        if (in > a1) {
            int tmp = in;
            in = a1;
            a1 = tmp;
        }

        if (in > a2) {
            int tmp = in;
            in = a2;
            a2 = tmp;
        }

        if (in > a3) {
            int tmp = in;
            in = a3;
            a3 = tmp;
        }
    }

    printf("%d\n", a3);

    return 0;
}
