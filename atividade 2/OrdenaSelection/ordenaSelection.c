#include <stdio.h>
#include <stdlib.h>

int ordenaNumerosSelection(int*, int);

int main() {

    int N;
    scanf("%d", &N);

    int *v = (int*)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    int trocas = ordenaNumerosSelection(v, N);

    for (int i = 0; i < N; i++) {
        printf("%d%s", v[i], (i < N - 1 ? " " : "\n"));
    }

    printf("%d\n", trocas);

    free(v);
    return 0;
}

int ordenaNumerosSelection(int *v, int n) {

    int trocas = 0;

    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], (i < n - 1 ? " " : "\n"));
    }

    for (int i = 0; i < n - 1; i++) {

        int posicaoMenor = i; 
        for (int j = i + 1; j < n; j++) {
            if( v[j] < v[posicaoMenor]) {
                posicaoMenor = j;
                trocas++;
            }
        }
        int aux = v[i];
        v[i] = v[posicaoMenor];
        v[posicaoMenor] = aux;
        //trocas++;

        for (int i = 0; i < n; i++) {
            printf("%d%s", v[i], (i < n - 1 ? " " : "\n"));
        }
    }

    return trocas;
}