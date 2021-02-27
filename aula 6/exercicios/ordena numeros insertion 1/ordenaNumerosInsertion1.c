#include <stdio.h>
#include <stdlib.h>

void ordenaNumerosInsertion1(int *, int);

int main() {

    int N;
    scanf("%d", &N);

    int *v = (int*)malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    ordenaNumerosInsertion1(v, N);

    for(int i = 0; i < N; i++) {
        printf("%d%s", v[i], (i < N - 1 ? " " : "\n"));
    }

    free(v);
    return 0;
}

void ordenaNumerosInsertion1(int *v, int n) {
    for (int i = 0; i < n; i++) {

        int chave = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > chave) {
            v[ j + 1] = v[j];
            v[j] = chave;
            j--;
        }
    }
}