#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char *geraNome(int);
char *geraMatricula(int);

int main() {

    srand(time(NULL));

    int N = (rand()%10000) + 1;
    char *pNome, *pMatr;

    printf("%d\n", N);

    for(int i = 0; i < N; i++) {

        printf("%s\n", geraNome((rand()%100)+2));
        printf("%s\n", geraMatricula(12));

        int K = (rand()%10) + 1;
        printf("%d\n", K);
        for(int j = 0; j < K; j++) {
            printf("%d%s", rand()%11, (j < K - 1 ? " " : "\n"));
        }
    }

    printf("%d\n", rand()%11);

    return 0;
}

char *geraNome(int n) {
    char *nome = (char*) malloc(sizeof(char) * n);
    int i;
    for(i = 0; i < n - 1; i++) {
        do {
            nome[i] = rand()%256;
        }while(!isalpha(nome[i]));
    }
    nome[i] = '\0';
    return nome;
}

char *geraMatricula(int n) {
    char *matricula = (char*) malloc(sizeof(char) * n);
    int i;
    for(i = 0; i < n - 1; i++) {
        do {
            matricula[i] = rand()%256;
        }while(!isdigit(matricula[i]));
    }
    matricula[i] = 0;
    return matricula;
}