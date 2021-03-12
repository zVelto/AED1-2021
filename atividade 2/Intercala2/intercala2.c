#include <stdio.h>
#include <stdlib.h>

void mergeSort(int*, int, int);
void intercala(int *, int, int, int);

int main() {

    int q1, q2;
    scanf("%d", &q1);
    scanf("%d", &q2);

    int n = q1 + q2;

    int *v = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    mergeSort(v, 0, n - 1);

    for(int i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }

    free(v);
    return 0;
}

void mergeSort(int *v, int primeiraPosicao, int ultimaPosicao) {

    if (primeiraPosicao < ultimaPosicao) {

        int posicaoMeio = (ultimaPosicao + primeiraPosicao) / 2;

        mergeSort(v, primeiraPosicao, posicaoMeio);
        mergeSort(v, posicaoMeio + 1, ultimaPosicao);
        intercala(v, primeiraPosicao, posicaoMeio, ultimaPosicao);
    }
}

void intercala(int *v, int primeiraPosicao, int posicaoMeio, int ultimaPosicao) {
    
    int tamanho = ultimaPosicao - primeiraPosicao + 1;

    int *vTemp = (int*)malloc(sizeof(int) * tamanho);

    int iTemp = 0, posicaoV1 = primeiraPosicao, posicaoV2 = posicaoMeio + 1;

    while(posicaoV1 <= posicaoMeio && posicaoV2 <= ultimaPosicao) {
        if(v[posicaoV1] < v[posicaoV2]) {
            vTemp[iTemp] = v[posicaoV1];
            iTemp++;
            posicaoV1++;
        } else {
            vTemp[iTemp] = v[posicaoV2];
            iTemp++;
            posicaoV2++;
        }
    }

    while (posicaoV1 <= posicaoMeio) {
        vTemp[iTemp] = v[posicaoV1];
        posicaoV1++;
        iTemp++;
    }
    
    while (posicaoV2 <= ultimaPosicao) {
        vTemp[iTemp] = v[posicaoV2];
        posicaoV2++;
        iTemp++;
    }

    for (int i = primeiraPosicao, j = 0; i <= ultimaPosicao; i++, j++) {
        v[i] = vTemp[j];
    }
}