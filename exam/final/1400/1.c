#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

bool Is_palindrom(int l, int r, char *s) {
    if (r <= l)
        return 1;
    if (s[l] != s[r - 1])
        return 0;
    return Is_palindrom(l + 1, r - 1, s);
}

int main() {
    char s[1000];
    scanf("%s", s);

    if (Is_palindrom(0, strlen(s), s))
        printf("Yes\n");
    else
        printf("No\n");
} 