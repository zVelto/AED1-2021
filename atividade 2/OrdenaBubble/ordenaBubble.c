#include <stdio.h>
#include <stdlib.h>

int ordenaBubble(int *, int);

int main() {

    int n;

    scanf("%d", &n);

    int *v = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int trocas = ordenaBubble(v, n);

    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], (i < n - 1 ? " " : "\n"));
    }

    printf("Trocas: %d\n", trocas);

    free(v);

    return 0;
}

int ordenaBubble(int *v, int n) {

    int trocas = 0;
    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], (i < n - 1 ? " " : "\n"));
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                int aux = v[j];
                v[j] = v[j + 1];
                v [j + 1] = aux;
                for (int i = 0; i < n; i++) {
                    printf("%d%s", v[i], (i < n - 1 ? " " : "\n"));
                }
                trocas++;
            }
        }
    }

    return trocas;
}