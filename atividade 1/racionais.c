#include <stdio.h>
#include <math.h>

struct tRacional {
    int numerador;
    int denominador;
};

int MDC(int, int);

struct tRacional reduz(struct tRacional);

struct tRacional racional(int, int);

struct tRacional negativo(struct tRacional);

struct tRacional soma(struct tRacional, struct tRacional);

struct tRacional sub(struct tRacional, struct tRacional);

struct tRacional mult(struct tRacional, struct tRacional);

struct tRacional div(struct tRacional, struct tRacional);

int main() {

    int n1, d1, n2, d2;
    char operador;

    while(scanf("%d %d %c %d %d", &n1, &d1, &operador, &n2, &d2) != EOF) {

        struct tRacional r1 = racional(n1, d1);
        struct tRacional r2 = racional(n2, d2);

        struct tRacional racional;

        if (operador == '+') {
            racional = soma(r1, r2);

        } else if (operador == '-') {
            racional = sub(r1, r2);

        } else if (operador == '*') {
            racional = mult(r1, r2);

        } else {
            racional = div(r1, r2);
        }

        printf("%d %d\n", racional.numerador, racional.denominador);
    }

    return 0;
}

int MDC(int n1, int n2) {

    if(n1 < 0) {
        n1 = -n1;
    }

    if(n2 < 0) {
        n2 = -n2;
    }

    int resto = n1 % n2;

    while (resto != 0) {
        n1 = n2;
        n2 = resto;
        resto = n1 % n2;
    }

    return n2;
}

/*
int MMC(int a, int b) {
    for (int i = 1; i <= a * b; i++) {
        if(i%a == 0 && i%b == 0) {
            return i;
        }
    }
}
*/

struct tRacional reduz(struct tRacional r1) {

    struct tRacional racional;

    int mdc = MDC(r1.numerador, r1.denominador);

    racional.numerador = r1.numerador / mdc;
    racional.denominador = r1.denominador / mdc;

    return racional;
}

/*
void denominadorComum(struct tRacional* r1, struct tRacional* r2) {

    int mmc = MMC(r1->denominador, r2->denominador);

    r1->numerador = (mmc / r1->denominador) * r1->numerador;
    r2->numerador = (mmc / r2->denominador) * r2->numerador;

    r1->denominador = mmc;
    r2->denominador = mmc;
}
*/

struct tRacional racional(int n1, int n2) {
    struct tRacional racional = { n1, n2 };
    return racional;
}

struct tRacional negativo(struct tRacional r) {
    struct tRacional racional;
    racional.numerador = - r.numerador;
    return racional;
}

struct tRacional soma(struct tRacional r1, struct tRacional r2) {
    struct tRacional racional;

    int denominadorComum = r1.denominador * r2.denominador;
    r1.numerador = (denominadorComum / r1.denominador) * r1.numerador;
    r2.numerador = (denominadorComum / r2.denominador) * r2.numerador;

    r1.denominador = denominadorComum;
    r2.denominador = denominadorComum;
    
    //denominadorComum(&r1, &r2);

    racional.numerador = r1.numerador + r2.numerador;
    racional.denominador = r1.denominador;

    racional = reduz(racional);

    return racional;
}

struct tRacional sub(struct tRacional r1, struct tRacional r2) {
    struct tRacional racional;
    
    //denominadorComum(&r1, &r2);

    int denominadorComum = r1.denominador * r2.denominador;
    r1.numerador = (denominadorComum / r1.denominador) * r1.numerador;
    r2.numerador = (denominadorComum / r2.denominador) * r2.numerador;

    r1.denominador = denominadorComum;
    r2.denominador = denominadorComum;

    racional.numerador = r1.numerador - r2.numerador;
    racional.denominador = r1.denominador;

    racional = reduz(racional);

    return racional;
}

struct tRacional mult(struct tRacional r1, struct tRacional r2) {
    struct tRacional racional;

    racional.numerador = r1.numerador * r2.numerador;
    racional.denominador = r1.denominador * r2.denominador;

    racional = reduz(racional);

    return racional;
}

struct tRacional div(struct tRacional r1, struct tRacional r2) {
    struct tRacional racional;

    racional.numerador = r1.numerador * r2.denominador;
    racional.denominador = r1.denominador * r2.numerador;

    racional = reduz(racional);

    return racional;
}