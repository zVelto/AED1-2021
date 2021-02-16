#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K, E = 100;
    scanf("%d %d", &N, &K);
    int* nuvens = (int*)malloc(sizeof(int*) * N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &nuvens[i]);
    }

    if(nuvens[N - 1] == 1) {
        E -= 2;
    }

    for(int i = 0; i < N; i += K) {
        E--;
        if(nuvens[i] == 1) {
            E -= 2;
        }
    }

    printf("%d\n", E);

    free(nuvens);
    return 0;
}