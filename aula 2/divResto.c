#include <stdio.h>

void divResto(int* a, int* b);

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    divResto(&a, &b);
    printf("%d %d", a, b);
    return 0;
}

void divResto(int* a, int* b) {
    int auxA, auxB;
    auxA = *a / *b;
    auxB = *a % *b;
    *a = auxA;
    *b = auxB;
}