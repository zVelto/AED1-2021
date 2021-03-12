#include <stdio.h>
#include <stdlib.h>

int buscaBin(int*, int, int, int);

int main() {

    int n;

    scanf("%d", &n);

    int *v = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int k;

    while (scanf("%d", &k) != EOF) {

        int resultado = buscaBin(v, 0, n - 1, k);

        if (resultado == -1) {
            printf("VALOR %d NAO LOCALIZADO NA COLECAO\n", k);
        } else {
            printf("VALOR %d LOCALIZADO NA COLECAO\n", k);
        }

    }

    free(v);
    return 0;
}

int buscaBin(int* v, int esq, int dir, int x) {
    int meio;

    if(esq <= dir) {
        meio = (esq + dir) / 2;

        if (v[meio] == x) {
            return meio;

        } else if (v[meio] > x) {
            for (int i = meio; i <= dir; i++) {
                printf("%d%s", v[i], (i < dir ? " " : "\n"));
            }
            return buscaBin(v, esq, meio - 1, x);

        } else {
            for (int i = esq; i <= meio; i++) {
                printf("%d%s", v[i], (i < meio ? " " : "\n"));
            }
            return buscaBin(v, meio + 1, dir, x);

        }
    }
    return -1;
}