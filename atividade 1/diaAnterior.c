#include <stdio.h>
#include <stdbool.h>

bool bissexto(int);

int main() {

    int data[3];
    int dataAnt[3];
    int meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    scanf("%d %d %d", &data[0], &data[1], &data[2]);

    if(bissexto(data[2]) == 1) {
        meses[1] = 29;
    }

    if(data[0] == 1 && data[1] == 1) {
        dataAnt[0] = 31;
        dataAnt[1] = 12;
        dataAnt[2] = data[2] - 1;
    } else if (data[0] == 1) {
        dataAnt[0] = meses[data[1] - 2];
        dataAnt[1] = data[1] - 1;
        dataAnt[2] = data[2];
    } else {
        dataAnt[0] = data[0] - 1;
        dataAnt[1] = data[1];
        dataAnt[2] = data[2];
    }

    printf("%d %d %d\n", dataAnt[0], dataAnt[1], dataAnt[2]);

    return 0;
}

bool bissexto(int ano) {
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