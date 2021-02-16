#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool bissexto(int);
void avancarOuRetrocederData(int*, char, int*);

int main() {

    int N;
    scanf("%d", &N);

    //int** resultados = (int**)malloc(sizeof(int**) * N);

    for(int i = 0; i < N; i++) {

        //int* data = (int*)malloc(sizeof(int*) * 3);
        int data[3], numComandos;
        int meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        scanf("%d %d %d", &data[0], &data[1], &data[2]);

        if(bissexto(data[2]) == 1) {
            meses[1] = 29;
        }

        scanf("%d", &numComandos);

        char *comandos = (char*)malloc(sizeof(char*) * numComandos);

        scanf("%s", comandos);

        for (int j = 0; j < numComandos; j++) { 
            avancarOuRetrocederData(data, comandos[j], meses);
        }

        printf("%d/%d/%d\n", data[0], data[1], data[2]);

        /*
        *&resultados[i][0] = *&data[0];
        *&resultados[i][1] = *&data[1];
        *&resultados[i][2] = *&data[2];
        */

        free(comandos);
    }

    /*
    for (int i = 0; i < N; i++) {
        printf("chegou aqui\n");
        printf("%d/%d/%d\n", resultados[i][0], resultados[i][1], resultados[i][2]);
    }

    free(resultados);
    */

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

void avancarOuRetrocederData(int* data, char comando, int* meses) {

    if(comando == '<') {

        if(data[0] == 1 && data[1] == 1) {
            data[0] = 31;
            data[1] = 12;
            data[2] = data[2] - 1;

        } else if (data[0] == 1) {
            data[0] = meses[data[1] - 2];
            data[1] = data[1] - 1;
            data[2] = data[2];

        } else {
            data[0] = data[0] - 1;
            data[1] = data[1];
            data[2] = data[2];
        }
    } else {

        if(data[0] == 31 && data[1] == 12) {
            data[0] = 1;
            data[1] = 1;
            data[2] = data[2] + 1;

        } else if (data[0] == meses[data[1] - 1]) {
            data[0] = 1;
            data[1] = data[1] + 1;
            data[2] = data[2];

        } else {
            data[0] = data[0] + 1;
            data[1] = data[1];
            data[2] = data[2];
        }
    }
}