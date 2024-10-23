// لوزی‌های ستاره‌ای
// بدون تابع 

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    char res[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = ' ';
        }
    }

    int l = n / 2, r = n / 2;
    for (int i = 0; i < n; i++) {
        for (int j = l; j <= r; j++) {
            res[i][j] = '*';
        }
        if (i < n / 2) {
            l--;
            r++;
        } else {
            l++;
            r--;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2*n; j++) {
            printf("%c",res[i][j%n]);
        }
        printf("\n");
    }

    return 0;
}
