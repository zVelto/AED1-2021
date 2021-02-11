#include <stdio.h>

int somaElementos(int* v, int N) {
    long int s = 0, i;

    for (i = 0; i < N; i++) {
        s += v[i];
    }
    
    return s;
}

int main() {
    long int N;

    scanf("%ld", &N);

    int v[N], i;

    for (i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    long int soma = somaElementos(v, N);

    printf("%ld\n", soma);

    return 0;
}