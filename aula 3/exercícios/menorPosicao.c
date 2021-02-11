#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, menorValor, posicao;
    scanf("%d", &N);
    int* v = (int*)malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &v[i]);

        if(i == 0) {
            posicao = i;
            menorValor = v[i];
        } else if (v[i] < menorValor) {
            posicao = i;
            menorValor = v[i];
        }
    }

    printf("Menor valor: %d\n", menorValor);
    printf("Posicao: %d\n", posicao);
}