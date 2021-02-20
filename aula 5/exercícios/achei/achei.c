#include <stdio.h>
#include <stdlib.h>

int main() {

    int N, M;

    scanf("%d", &N);

    int *v1 = (int*)malloc(sizeof(int*) * N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &v1[i]);
    }

    scanf("%d", &M);

    int *v2 = (int*)malloc(sizeof(int*) * M);

    for (int i = 0; i < M; i++) {
        scanf("%d", &v2[i]);
    }

    for (int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if (v2[i] == v1[j]) {
                printf("ACHEI\n");
                break;
            }
            if (j == N - 1) {
                printf("NAO ACHEI\n");
            }
        }
    }

    free(v1);
    free(v2);

    return 0;
}