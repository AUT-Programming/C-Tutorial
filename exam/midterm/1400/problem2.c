#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_testcases(){
    const int max_branches = 20;
    const int num_cities = 50;
    const int max_location = 60;
    long t = time(NULL);
    printf("%ld\n", t);
    srand(t);
    int n = rand() % num_cities + 4;
    printf("%d\n", n);
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", rand() % max_location - 30, rand() % max_branches + 4);
    }
}

int main(){
//    generate_testcases();
//    return 0;
    int n;
    scanf("%d", &n);
    int locations[n], branches[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &locations[i], &branches[i]);
    }
    long distances[n];
    for (int i = 0; i < n; i++) {
        long distance = 0;
        for (int j = 0; j < n; j++) {
            distance += branches[j] * abs(locations[i] - locations[j]);
        }
        distances[i] = distance;
    }
    int idx = 0;
    for (int i = 1; i < n; ++i) {
        if (distances[i] < distances[idx])
            idx = i;
    }
    printf("%d", idx + 1);
}
