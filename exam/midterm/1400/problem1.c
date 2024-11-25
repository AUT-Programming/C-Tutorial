#include <stdio.h>

int check_pattern(char arr[], int size) {
    char stack[size];
    int l = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == '(') {
            stack[++l] = arr[i];
            continue;
        }
        if (l < 0 || stack[l] != '(') {
            return 0;
        }
        l--;
    }
    if (l < 0)
        return 1;
    else
        return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    char input_chars[n];
    for (int i = 0; i < n; i++) {
        scanf(" %c", &input_chars[i]);
    }
    if (check_pattern(input_chars, n))
        printf("1");
    else
        printf("0");
    return 0;
}
