#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    int N = (rand()%100000) + 1;

    printf("%d\n", N);

    for (int i = 0; i < N; i++) {
        printf("%d%s", rand(), ( i < N - 1 ? " " : "\n"));
    }

    int M = (rand()%1000) + 1;

    printf("%d\n", M);

    for (int i = 0; i < M; i++) {
        printf("%d\n", rand());
    }

    return 0;
}