#include <stdio.h>
#include <stdlib.h>

int particiona(int *, int, int, int);

int main() {

    int q, p;

    scanf("%d", &q);
    scanf("%d", &p);

    int *v = (int*)malloc(sizeof(int) * q);

    for (int i = 0; i < q; i++) {
        scanf("%d", &v[i]);
    }

    particiona(v, 0, q - 1, p);

    for (int i = 0; i < q; i++) {
        printf("%d\n", v[i]);
    }

    free(v);
    return 0;
}

int particiona(int *v, int primeiraPosicao, int ultimaPosicao, int p) {

    int aux = v[p];
    v[p] = v[ultimaPosicao];
    v[ultimaPosicao] = aux;

    int posicaoAtual = primeiraPosicao;
    int posicaoMenor = primeiraPosicao - 1;

    for(posicaoAtual, posicaoMenor; posicaoAtual < ultimaPosicao; posicaoAtual++){

        if(v[posicaoAtual] < v[ultimaPosicao]) {
            posicaoMenor++;
            int aux = v[posicaoMenor];
            v[posicaoMenor] = v[posicaoAtual];
            v[posicaoAtual] = aux;
        }
    }

    aux = v[posicaoMenor + 1];
    v[posicaoMenor + 1] = v[ultimaPosicao];
    v[ultimaPosicao] = aux;
    return posicaoMenor + 1;
}