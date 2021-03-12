#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

struct tRacional {
    int numerador;
    int denominador;
};

bool comparaRacionais(struct tRacional, struct tRacional);

int main() {

    int n;

    scanf("%d", &n);

    struct tRacional *racionais = (struct tRacional*)malloc(sizeof(struct tRacional) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &racionais[i].numerador, &racionais[i].denominador);
    }

    struct tRacional racional;

    while(scanf("%d %d", &racional.numerador, &racional.denominador) != EOF) {

        bool encontrado = false;

        for (int i = 0; i < n; i++) {
            if (comparaRacionais(racional, racionais[i])) {
                encontrado = true;
            }
        }

        if (encontrado == 1) {
            printf("S\n");
        } else {
            printf("N\n");
        }

    }

    free(racionais);

    return 0;
}

bool comparaRacionais(struct tRacional r1, struct tRacional r2) {
    if (r1.numerador * r2.denominador == r1.denominador * r2.numerador) {
        return true;
    } else {
        return false;
    }
}