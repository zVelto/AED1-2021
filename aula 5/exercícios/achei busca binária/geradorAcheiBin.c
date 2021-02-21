#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    int N = (rand()%100000) + 1;

    printf("%d\n", N);

    int *v = (int*)malloc(sizeof(int*) * N);

    for (int i = 0; i < N; i++) {

        int salto = (rand()%10) + 1;

        if (i == 0) {
            v[i] = salto;
        
        } else {
            v[i] = salto + v[i - 1];
        }

        printf("%d%s", v[i], ( i < N - 1 ? " " : "\n"));

    }

    int M = (rand()%1000) + 1;

    printf("%d\n", M);

    for (int i = 0; i < M; i++) {
        printf("%d\n", rand());
    }

    return 0;
}