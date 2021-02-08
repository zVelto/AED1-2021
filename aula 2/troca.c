#include<stdio.h>

void troca(long int*, long int*);

int main() {
    long int a, b;
    scanf("%ld %ld", &a, &b);
    troca(&a, &b);
    printf("%ld %ld", a, b);
    return 0;
}

void troca(long int* a, long int* b) {
    long int aux = *a;
    *a = *b;
    *b = aux;
}