#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

char check_words[][20] = {"sefr", "yek", "do", "se", "chahar", "panj", "shesh", "haft", "hasht", "noh", "dah", "yazdah", "davazdah", "sizdah", "chahardah", "panzdah", "shanzdah", "hefdah", "hejdah", "nozdah", "bist", "si", "chehel", "panjah", "shast", "haftad", "hashtad", "navad", "sad", "devist", "sisad", "chaharsad", "pansad", "sheshsad", "haftsad", "hashtsad", "nohsad", "hezar", "va"};
int motenazer[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 40, 50, 60, 70, 80, 90, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, -1};

bool Is_equal(char *a, int sizea, char *b, int sizeb) {
    if (sizea != sizeb)
        return 0;
    
    for (int i = 0; i < sizea; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}

int val(char *s, int size) {
    for (int i = 0; i < 39; i++) {
        int sz = strlen(check_words[i]);
        if (Is_equal(check_words[i], sz, s, size))
            return motenazer[i];
    }
    return -2;
}

void solve() {
    char s[300];
    gets(s);
    int n = strlen(s);
    char tmp[300];
    int sz = 0;
    int ans = 0;
    int last = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] != ' ')
            tmp[sz++] = s[i];
        else {
            tmp[sz] = '\0';
            int value = val(tmp, sz);
            sz = 0;
            tmp[sz] = '\0';

            // printf("check val = %d\n", value);
            if (value == -1) {
                last = -1;
                continue;
            }
            else if (value == 1000) {
                if (ans == 0)
                    ans = 1000;
                else
                    ans *= 1000;
            }
            else {
                if (last == -1)
                    ans += value;
                else {
                    if (ans != 0)
                        printf("%d", ans);
                    ans = 0;
                    ans += value;
                }
            }

            last = value;
        }
    }

    if (sz) {
        tmp[sz] = '\0';
        int value = val(tmp, sz);
        sz = 0;
        tmp[sz] = '\0';

        if (value == 1000) {
            if (ans == 0)
                ans = 1000;
            else
                ans *= 1000;
        }
        else if (value != -1) {
            if (last == -1)
                ans += value;
            else {
                if (ans != 0)
                    printf("%d", ans);
                ans = 0;
                ans += value;
            }
        }
    }
    if (ans)
        printf("%d", ans);
    printf("\n");
}

int main() {
    int q = 0;
    scanf("%d\n", &q);
    while (q--) {
        solve();
    }
}