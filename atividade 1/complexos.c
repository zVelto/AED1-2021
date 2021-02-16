#include <stdio.h>

struct tComplex {
    int x;
    int y;
};

struct tComplex complexo(int, int);

struct tComplex soma(struct tComplex, struct tComplex);

struct tComplex sub(struct tComplex, struct tComplex);

struct tComplex mult(struct tComplex, struct tComplex);

struct tComplex div(struct tComplex, struct tComplex);

int main() {

    int x1, y1, x2, y2;
    char operador, i1, i2;

    while(scanf("%d %d%c %c %d %d%c", &x1, &y1, &i1, &operador, &x2, &y2, &i2) != EOF) {
        struct tComplex c1 = complexo(x1, y1);
        struct tComplex c2 = complexo(x2, y2);

        struct tComplex cplex;

        if (operador == '+') {
            cplex = soma(c1, c2);

        } else if (operador == '-') {
            cplex = sub(c1, c2);

        } else if (operador == '*') {
            cplex = mult(c1, c2);

        } else {
            cplex = div(c1, c2);
        }

        if(cplex.y >= 0) {
            printf("%d +%di\n", cplex.x, cplex.y);
        } else {
            printf("%d %di\n", cplex.x, cplex.y);
        }

    }

    return 0;
}

struct tComplex complexo(int a, int b) {
    struct tComplex cplex;

    cplex.x = a;
    cplex.y = b;

    return cplex;
}

struct tComplex soma(struct tComplex c1, struct tComplex c2) {
    struct tComplex cplex;

    cplex.x = c1.x + c2.x;
    cplex.y = c1.y + c2.y;

    return cplex;
}

struct tComplex sub(struct tComplex c1, struct tComplex c2) {
    struct tComplex cplex;

    cplex.x = c1.x - c2.x;
    cplex.y = c1.y - c2.y;

    return cplex;
}

struct tComplex mult(struct tComplex c1, struct tComplex c2) {
    struct tComplex cplex;

    cplex.x = (c1.x * c2.x) - (c1.y * c2.y);
    cplex.y = (c1.x * c2.y) + (c1.y * c2.x);

    return cplex;
}

struct tComplex div(struct tComplex c1, struct tComplex c2) {
    struct tComplex cplex;

    struct tComplex conjugado = { c2.x, -c2.y};

    struct tComplex numerador = mult(c1, conjugado);

    struct tComplex produto = mult(c2, conjugado);

    int denominador = produto.x + produto.y;

    cplex.x = numerador.x / denominador;
    cplex.y = numerador.y / denominador;

    return cplex;
}