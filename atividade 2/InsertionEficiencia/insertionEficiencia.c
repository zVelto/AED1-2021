#include <stdio.h>
#include <stdlib.h>

void insercao(int *, int);

int main() {

    int n;
    scanf("%d", &n);

    int *v = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    insercao(v, n);

    free(v);
    return 0;
}

void insercao(int *v, int n) {

    int trocas = 0;

    for (int i = 1; i < n; i++) {

        int chave = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            v[j] = chave;
            j--;
            trocas++;
        }
    }

    printf("%d\n", trocas);
}