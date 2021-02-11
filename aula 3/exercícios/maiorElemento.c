#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

    do {
        scanf("%d", &N);

        if(N != 0) {
            int maiorValor, posicao;
            int* v = (int*)malloc(sizeof(int) * N);

            for(int i = 0; i < N; i++) {
                scanf("%d", &v[i]);

                if(i == 0) {
                    posicao = i;
                    maiorValor = v[i];
                } else if (v[i] > maiorValor) {
                    posicao = i;
                    maiorValor = v[i];
                }
            }
            printf("%d %d\n", posicao, maiorValor);
        }

    } while(N != 0);
}