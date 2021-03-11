#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *, int, int);
void intercala(int *, int, int, int);

int main() {
    int *v, n, i;
    while(scanf("%d", &n) != EOF)
    {
        v = (int*) malloc((n+2) * sizeof(int));
        for(i=0; i<n; i++)
        {
            scanf("%d", &v[i]);
        }
        /*
            Ao chamar se passa n-1 (indice do ultimo elemento do vetor)
            comentei em aula que podia ser n, mas teria que pensar nisso
            quando implementar o intercala. Pois bem, no intercala foi
            considerado que d seria o indice o ultimo elemento, entao
            na chamada inicial se passa n-1 e nao n.
            Linha 26 com erro: mergeSort(v, 0, n);
            Linha 26 corrigida: mergeSort(v, 0, n-1);
        */
        mergeSort(v, 0, n-1);

        for(i=0; i<n; i++)
        {
            printf("%d%s", v[i], (i<n-1?" ":"\n"));
        }
        free(v);
    }
    return 0;
}

void mergeSort(int *v, int e, int d) {
    printf("primeira posicao: %d, ultima posicao: %d\n", e, d);
    int meio;

    if (e < d) {
        meio = (e + d) / 2;
        mergeSort(v, e, meio);
        mergeSort(v, meio + 1, d);
        intercala(v, e, meio + 1, d);
    }
}

void intercala(int *v, int e, int m, int d) {
    int *vTemp, lim_esq = m - 1, tamanho = d - e + 1, i, j, iTemp = 0;
    vTemp = (int*)malloc(sizeof(int) * tamanho);

    for (i = e, j = m; i <= lim_esq && j <= d; iTemp++) {
        if (v[i] < v[j]) {
            vTemp[iTemp] = v[i];
            i++;
        } else {
            vTemp[iTemp] = v[j];
            j++;
        }
    }

    for (; i <= lim_esq; iTemp++, i++) {
        vTemp[iTemp] = v[i];
    }

    for (; j <= d; iTemp++, j++) {
        vTemp[iTemp] = v[j];
    }

    for (i = e, j = 0; i <= d; i++, j++) {
        v[i] = vTemp[j];
    }

    free(vTemp);
}