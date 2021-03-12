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

    for(int i = 0; i < n; i++) {
        printf("%d%s", v[i], (i < n - 1 ? " " : "\n"));
    }

    free(v);
    return 0;
}

void insercao(int *v, int n) {
    for (int i = 1; i < n; i++) {

        int chave = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];

            for(int k = 0; k < n; k++) {
                printf("%d%s", v[k], (k < n - 1 ? " " : "\n"));
            }

            v[j] = chave;
            j--;
        }
    }
}