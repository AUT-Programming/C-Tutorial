#include <stdio.h>
#include <stdbool.h>

int nextGoodNumber(int counter, int current) {
    return current + counter;
}

int countFactors(int num) {
    int count = 0;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            count++;
            if (i != num / i) {
                count++;
            }
        }
    }
    return count;
}

int determineK2(int k, int good_number) {
    int sqrt_val = 1;
    while (sqrt_val * sqrt_val <= good_number) {
        sqrt_val++;
    }
    sqrt_val--;
    if (sqrt_val * sqrt_val == good_number) {
        return (k % 2 == 0) ? (k / 2 + 1) : ((k - 1) / 2 + 1);
    } else {
        return (k % 2 == 0) ? (k / 2) : (k / 2 + 1);
    }
}

int main() {
    int k;
    scanf("%d", &k);

    int good_number = 0;
    int good_number_counter = 0;
    bool is_finished = false;

    while (!is_finished) {
        good_number_counter++;
        good_number = nextGoodNumber(good_number_counter, good_number);
        
        int k2 = determineK2(k, good_number);
        int factor_counter = countFactors(good_number);
        
        if (factor_counter >= k2) {
            printf("%d\n", good_number);
            is_finished = true;
        }
    }

    return 0;
}
