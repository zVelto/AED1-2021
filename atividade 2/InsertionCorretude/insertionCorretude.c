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

    int i;

    for (i = 1; i < n; i++) {

        printf("Sublista Ordenada: ");

        for (int k = 0; k < i; k++) {
            printf("%d%s", v[k], (k < i - 1 ? " " : "\n"));
        }

        printf("Sublista Desordenada: ");

        for (int k = i; k < n; k++) {
            printf("%d%s", v[k], (k < n - 1 ? " " : "\n"));
        }

        int chave = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            v[j] = chave;
            j--;
        }
    }

    printf("Sublista Ordenada: ");

        for (int k = 0; k < i; k++) {
            printf("%d%s", v[k], (k < i - 1 ? " " : "\n"));
        }

        printf("Sublista Desordenada:\n");

        for (int k = i; k < n; k++) {
            printf("%d%s", v[k], (k < n - 1 ? " " : "\n"));
        }
}