#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ordenaVetorDiretamente(int *, int);
void ordenaVetorInversamente(int *, int);

int main() {

    int n;

    while(scanf("%d", &n) != EOF) {

        if(n != 0) {

            int *v = (int*)malloc(sizeof(int) * n);
            int *vOrdenadoDiretamente = (int*)malloc(sizeof(int) * n);
            int *vOrdenadoInversamente = (int*)malloc(sizeof(int) * n);

            for (int i = 0; i < n; i++) {
                scanf("%d", &v[i]);
            }

            for( int i = 0; i < n; i++) {
                vOrdenadoDiretamente[i] = v[i];
                vOrdenadoInversamente[i] = v[i];
            }

            ordenaVetorDiretamente(vOrdenadoDiretamente, n);
            ordenaVetorInversamente(vOrdenadoInversamente, n);

            bool eOrdenadoDiretamente = true;
            bool eOrdenadoInversamente = true;

            for (int i = 0; i < n; i++) {
                if (v[i] != vOrdenadoDiretamente[i]) {
                    eOrdenadoDiretamente = false;
                }
                if(v[i] != vOrdenadoInversamente[i]) {
                    eOrdenadoInversamente = false;
                }
            }

            // for (int i = 0; i < n; i++) {
            //     printf("%d%s", v[i], (i < n - 1 ? " " : "\n"));
            // }

            // for (int i = 0; i < n; i++) {
            //     printf("%d%s", vOrdenadoDiretamente[i], (i < n - 1 ? " " : "\n"));
            // }

            // for (int i = 0; i < n; i++) {
            //     printf("%d%s", vOrdenadoInversamente[i], (i < n - 1 ? " " : "\n"));
            // }

            // printf("\n");

            if(eOrdenadoDiretamente == 1 || eOrdenadoInversamente == 1) {
                printf("S\n");
            } else {
                printf("N\n");
            }

            free(v);
            free(vOrdenadoDiretamente);
            free(vOrdenadoInversamente);

        } else {
            printf("S\n");
        }
    }

    return 0;
}

void ordenaVetorDiretamente(int *v, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                int aux = v[j];
                v[j] = v[j + 1];
                v [j + 1] = aux;
            }
        }
    }
}

void ordenaVetorInversamente(int *v, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j + 1] > v[j]) {
                int aux = v[j];
                v[j] = v[j + 1];
                v [j + 1] = aux;
            }
        }
    }
}