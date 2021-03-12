#include <stdio.h>
#include <stdlib.h>

int insercao(int *, int);

int main() {

    int n;
    scanf("%d", &n);

    int *v = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int trocas = insercao(v, n);

    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], (i < n - 1 ? " " : "\n"));
    }

    printf("Trocas:%d\n", trocas);

    if( trocas == 0) {
        printf("MELHOR CASO\n");

    } else if (trocas == (n * (n - 1)) / 2) {
        printf("PIOR CASO\n");
    } else {
        printf("CASO ALEATORIO\n");
    }

    free(v);
    return 0;
}

int insercao(int *v, int n) {

    int trocas = 0;

    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], (i < n - 1 ? " " : "\n"));
    }

    for (int i = 1; i < n; i++) {

        int chave = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            v[j] = chave;
            j--;

            for (int i = 0; i < n; i++) {
                printf("%d%s", v[i], (i < n - 1 ? " " : "\n"));
            }

            trocas++;
        }
    }

    return trocas;
}