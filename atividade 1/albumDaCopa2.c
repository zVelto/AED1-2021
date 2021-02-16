#include <stdio.h>
#include <stdlib.h>

int main() {

    int N, M;

    scanf("%d", &N);
    scanf("%d", &M);

    int* figTotal = (int*)malloc(sizeof(int*) * N);

    for(int i = 1; i <= N; i++) {
        figTotal[i - 1] = i; 
    }

    int* figCompradas = (int*)malloc(sizeof(int*) * M);

    int figFaltantes = N;

    for (int i = 0; i < M; i++) {
        scanf("%d", &figCompradas[i]);
    }

    for (int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(figTotal[i] == figCompradas[j]) {
                figFaltantes--;
                break;
            }
        }
    }

    printf("%d\n", figFaltantes);

    free(figCompradas);
    free(figTotal);

    return 0;
}