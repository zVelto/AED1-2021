#include <stdio.h>
#include <stdlib.h>

int main() {

    int N, Q;

    scanf("%d", &N);

    char** S = (char**)malloc(sizeof(char*) * N);

    for (int i = 0; i < N; i++) {
        S[i] = malloc(sizeof(char*) * 26);
    }

    for(int i = 0; i < N; i++) {
        scanf("%s", S[i]);
    }

    scanf("%d", &Q);

    for (int i = 0; i < Q; i++) {
        char palavra[26];
        int vezes = 0;

        scanf("%s", palavra);

        for (int j = 0; j < N; j++) {

            int index = 0;

            while( palavra[index] == S[j][index]) {
                if( palavra[index] == '\0' || S[j][index] == '\0') {
                    break;
                }
                index++;
            }

            if( palavra[index] == '\0' && S[j][index] == '\0') {
                vezes++;
            }
        }

        printf("%d\n", vezes);
    }

    for (int i = 0; i < N; i++) {
        free(S[i]);
    }

    free(S);

    return 0;
}