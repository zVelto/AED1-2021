#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char *geraPalavra(int);

int main() {

    srand(time(NULL));

    int N = (rand()%1000) + 1;

    printf("%d\n", N);

    int qtdLetras;

    for(int j = 0; j < N; j++) {
        
        printf("%s\n", geraPalavra((rand()%25) + 2));
    }

    int Q = (rand()%1000) + 1;

    printf("%d\n", Q);

    for(int j = 0; j < Q; j++) {
            
        printf("%s\n", geraPalavra((rand()%25) + 2));
    }

    return 0;
}

char *geraPalavra(int n) {
    char *str = (char*)malloc(sizeof(char) * n);
    int i;
    for(i = 0; i < n - 1; i++) {
        do{
            str[i] = rand()%256;
        }while(!isalpha(str[i]));
    }
    str[i] = '\0';
    return str;
}