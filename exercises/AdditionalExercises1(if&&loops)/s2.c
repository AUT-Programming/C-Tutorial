#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    long double in[n];
    long double mean = 0;
    for (int i = 0; i < n; i++) {
        scanf("%Lf", &in[i]);
        mean += in[i];
    }
    mean /= n;
    long double var = 0;
    for (int i = 0; i < n; i++) {
        var += (in[i] - mean) * (in[i] - mean);
    }
    var /= n;
    var = sqrtl(var);
    printf("%.3Lf\n%.3Lf\n", mean, var);
    return 0;
}