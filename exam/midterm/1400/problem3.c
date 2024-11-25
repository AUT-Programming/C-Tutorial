#include <stdio.h>

int check_asc(int arr[], int size, int start_index, int k) {
    if (start_index + k > size)
        return 0;
    for (int i = 1; i < k; ++i) {
        if (arr[start_index + i] <= arr[start_index + i - 1])
            return 0;
    }
    return 1;
}

int check_desk(int arr[], int size, int start_index, int k) {
    if (start_index + k > size)
        return 0;
    for (int i = 1; i < k; ++i) {
        if (arr[start_index + i] >= arr[start_index + i - 1])
            return 0;
    }
    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int input_set[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &input_set[i]);
    }
    k += 1;
    for (int i = 0; i <= n - k; ++i) {
        if (check_asc(input_set, n, i, k) || check_desk(input_set, n, i, k)) {
            printf("0");
            return 0;
        }
    }
    printf("1");
    return 0;
}
