#include <stdio.h>

int main() {
    char a1[200], a2[200];
    int len1, len2;
    scanf("%d %s %d %s", &len1, a1, &len2, a2);
    
    for (int i = len1 - 1; i >= 0; i--) a1[200 - len1 + i] = a1[i] - '0';
    for (int i = len2 - 1; i >= 0; i--) a2[200 - len2 + i] = a2[i] - '0';
    
    for (int i = 0; i < 200 - len1; i++) a1[i] = 0;
    for (int i = 0; i < 200 - len2; i++) a2[i] = 0;
    
    int frst = 199;
    for (int i = 199; i >= 3; i--) {
        int t = a1[i] + a2[i];
        a1[i] = t % 10;
        t /= 10;
        a1[i - 3] += t;
        if (a1[i]) frst = i;
    }

    for (; frst < 200; frst++) printf("%d", a1[frst]);
    printf("\n");

    return 0;
}