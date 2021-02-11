#include <stdio.h>

int main() {
    int N, i;

    scanf("%d", &N);
    long int v[N];
    long int soma = 0;

    for (i = 0; i < N; i++) {
        scanf("%ld", &v[i]);
        soma += v[i];
    }

    printf("%ld\n", soma);

    return 0;
}