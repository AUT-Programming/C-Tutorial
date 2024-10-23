#include <stdio.h>

int main() {
    int n, d;
    scanf("%d %d", &n, &d);

    long long ans = 0, sma = 0, smb = d;
    int in;
    int a[n];

    // Read and sum first array
    for (int i = 0; i < n; i++) {
        scanf("%d", &in);
        sma += in;
        a[i] = in;
    }

    // Read and compare second array
    for (int i = 0; i < n; i++) {
        scanf("%d", &in);
        smb += (a[i] < in) ? a[i] : in;
    }

    // Determine the smaller sum
    ans = (sma < smb) ? sma : smb;
    
    // Print result
    printf("%lld\n", ans);

    return 0;
}
