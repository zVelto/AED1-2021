#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, i = 0, saltos = 0;
    scanf("%d", &N);
    int* v = (int*)malloc(sizeof(int*) * N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    while (i < N - 1) {
        if(v[i+2] == 0) {
            saltos++;
            i += 2;
        } else {
            saltos++;
            i += 1;
        }
    }

    printf("%d\n", saltos);

    free(v);
    return 0;
}