#include <stdio.h>
#include <stdbool.h>

bool bissexto(long int);

int main() {

    long int v[3];
    long int meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    scanf("%ld %ld %ld", &v[0], &v[1], &v[2]);

    if(bissexto(v[2]) == 1) {
        meses[1] = 29;
    }

    if(v[1] >= 1 && v[1] <= 12) {
        if(v[0] >= 1 && v[0] <= meses[v[1] - 1]) {
            printf("DATA VALIDA\n");
        } else {
            printf("DATA INVALIDA\n");
        }
    }
    else {
        printf("DATA INVALIDA\n");
    }

    return 0;
}

bool bissexto(long int ano) {
    if(ano%400 == 0) {
        return true;
    } else if (ano%100 == 0) {
        return false;
    } else if (ano%4 == 0) {
        return true;
    } else {
        return false;
    }
}