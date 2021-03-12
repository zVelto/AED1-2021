#include <stdio.h>
#include <stdlib.h>

void quickSort(int *, int, int, int);
int particiona(int *, int, int, int);

int main()
{
    int n;

    scanf("%d", &n);

    int *v = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], (i < n - 1 ? " " : "\n"));
    }

    quickSort(v, 0, n - 1, n);

    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], (i < n - 1 ? " " : "\n"));
    }

    free(v);
    return 0;
}

void quickSort(int *v, int e, int d, int n)
{
    int p;
    if(e < d)
    {
        p = particiona(v, e, d, n);
        quickSort(v, e, p-1, n);
        quickSort(v, p+1, d, n);
    }
}

int particiona(int *v, int e, int d, int n)
{
    int aux, i, pm;
    for(i=e, pm=e-1; i<d; i++)
    {
        if(v[i] < v[d])
        {
            pm++;
            aux = v[i];
            v[i] = v[pm];
            v[pm] = aux;
        }

        for (int i = 0; i < n; i++) {
            printf("%d%s", v[i], (i < n - 1 ? " " : "\n"));
        }
    }
    aux = v[d];
    v[d] = v[pm+1];
    v[pm+1] = aux;

    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], (i < n - 1 ? " " : "\n"));
    }

    return pm+1;
}