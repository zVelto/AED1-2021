#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, pares = 0;
    scanf("%d", &N);
    int* v = (int*)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    for(int i = 0; i < N; i++) {
        if(v[i]%2 == 0) {
            pares++;
        }
        if(i%2 == 0) {
            printf("%d ", v[i]);
        }
    }
    printf("%d\n", pares);
}