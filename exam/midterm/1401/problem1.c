#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int x[3], y[3];

bool is_kamel(int n) {
    long long sum = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != 1 && i * i != n)
                sum += n / i;
        }
    }

    return (sum == n);
}

int det(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
    return a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
}

int main() {
    for (int i = 0; i < 3; i++)
        scanf("%d", &x[i]);
    for (int i = 0; i < 3; i++)
        scanf("%d", &y[i]);

    int dete = det(1, 1, 1, x[0], x[1], x[2], y[0], y[1], y[2]);
    if (dete < 0)
        dete *= -1;
    
    dete /= 2;

    if (is_kamel(dete))
        printf("Yes\n");
    else
        printf("No\n");

    
}