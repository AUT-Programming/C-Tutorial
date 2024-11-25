//عدد خوب
#include <stdio.h>

int factor_num(int num) {
    int result = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) { result++; }
    }
    return result;
}

int main() {
    int k;
    scanf("%d", &k);
    int i = 1;
    while (factor_num(i * (i + 1) / 2) < k) {
        i++;
    }
    printf("%d", i * (i + 1) / 2);
    return 0;
}
