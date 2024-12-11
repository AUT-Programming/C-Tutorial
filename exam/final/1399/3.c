#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

struct count{
    char word[20]; 
    int cnt;
};

int frequency(int rows, int len, char strings[rows][len], struct count *result) {
    int res_size = 0;
    char check[50];
    check[0] = '\0';
    for (int i = 0; i < rows; i++) {
        int ind = 0;
        check[0] = '\0';
        for (int j = 0; j < len; j++) {
            if (strings[i][j] == ' ') {
                check[ind] = '\0';
                // printf("%d %d = %s\n", i, j, check);
                bool tekrari = 0;
                for (int k = 0; k < res_size; k++) {
                    int sz = strlen(result[k].word);
                    if (sz != ind)
                        continue;

                    bool yeki = 1;
                    for (int t = 0; t < sz; t++)
                        if (check[t] != result[k].word[t])
                            yeki = 0;
                        
                    if (yeki) {
                        tekrari = 1;
                        result[k].cnt++;
                        break;
                    }
                }

                if (!tekrari) {
                    struct count tmp;
                    for (int k = 0; k <= ind; k++)
                        tmp.word[k] = check[k];
                    tmp.cnt = 1;

                    result[res_size++] = tmp;
                }
                ind = 0;
                continue;
            }
            if (strings[i][j] == '\0' || strings[i][j] == '\n')
                break;

            check[ind++] = strings[i][j];
        }
        
        if (ind == 0)
            continue;
        
        check[ind] = '\0';
        bool tekrari = 0;
        for (int k = 0; k < res_size; k++) {
            int sz = strlen(result[k].word);
            if (sz != ind)
                continue;

            bool yeki = 1;
            for (int t = 0; t < sz; t++)
                if (check[t] != result[k].word[t])
                    yeki = 0;
                
            if (yeki) {
                tekrari = 1;
                result[k].cnt++;
                break;
            }
        }

        if (!tekrari) {
            struct count tmp;
            for (int k = 0; k <= ind; k++)
                tmp.word[k] = check[k];
            tmp.cnt = 1;

            result[res_size++] = tmp;
        }

    }

    return res_size;
}

int main() {
    int rows, len;
    scanf("%d %d\n", &rows, &len);
    char s[rows][len];

    for (int i = 0; i < rows; i++)
        gets(s[i]);

    struct count res[10000];
    int size = frequency(rows, len, s, res);
    for (int i = 0; i < size; i++)
        printf("%s %d\n", res[i].word, res[i].cnt);
} 