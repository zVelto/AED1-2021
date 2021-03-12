#include <stdio.h>
#include <stdlib.h>

void intercala(int *, int, int *, int, int*);

int main() {

    int q1, q2;
    scanf("%d", &q1);
    scanf("%d", &q2);

    int *v1 = (int*)malloc(sizeof(int) * q1);
    int *v2 = (int*)malloc(sizeof(int) * q2);
    int *vr = (int*)malloc(sizeof(int) * (q1 + q2));

    for(int i = 0; i < q1; i++) {
        scanf("%d", &v1[i]);
    }

    for(int i = 0; i < q2; i++) {
        scanf("%d", &v2[i]);
    }

    intercala(v1, q1, v2, q2, vr);

    for(int i = 0; i < (q1 + q2); i++) {
        printf("%d\n", vr[i]);
    }

    free(v1);
    free(v2);
    free(vr);
    return 0;
}

void intercala(int *v1, int n1, int *v2, int n2, int *vr) {

    int iTemp = 0, posicaoV1 = 0, posicaoV2 = 0;

    while(posicaoV1 < n1 && posicaoV2 < n2) {
        if(v1[posicaoV1] < v2[posicaoV2]) {
            vr[iTemp] = v1[posicaoV1];
            iTemp++;
            posicaoV1++;
        } else {
            vr[iTemp] = v2[posicaoV2];
            iTemp++;
            posicaoV2++;
        }
    }

    while (posicaoV1 < n1) {
        vr[iTemp] = v1[posicaoV1];
        posicaoV1++;
        iTemp++;
    }
    
    while (posicaoV2 < n2) {
        vr[iTemp] = v2[posicaoV2];
        posicaoV2++;
        iTemp++;
    }
}