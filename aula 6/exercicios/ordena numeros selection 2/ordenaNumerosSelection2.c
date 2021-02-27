#include <stdio.h>
#include <stdlib.h>

void ordenaNumerosSelection2(int *, int);

int main() {

    int N;
    scanf("%d", &N);

    int *v = (int*)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    ordenaNumerosSelection2(v, N);

    for (int i = 0; i < N; i++) {
        printf("%d%s", v[i], (i < N - 1 ? " " : "\n"));
    }

    free(v);
    return 0;
}

void ordenaNumerosSelection2(int *v, int n) {
    for (int i = 0; i < n - 1; i++) {

        int posicaoMenor = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[posicaoMenor]) {
                posicaoMenor = j;
            }
        }
        int aux = v[i];
        v[i] = v[posicaoMenor];
        v[posicaoMenor] = aux;
    }
}