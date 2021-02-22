#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char *geraNome(int);

int main() {

    srand(time(NULL));

    int N = (rand()%10000) + 1;

    printf("%d\n", N);

    for(int i = 0; i < N; i++) {

        printf("%s\n", geraNome((rand()%50) + 2));

        int M = (rand()%40) + 11;
        printf("%d\n", M);
        for(int j = 0; j < M; j++) {
            printf("%s %d\n", geraNome((rand()%50)+2), (rand()%100) + 1);
        }
    }

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