#include <stdio.h>
#include <stdlib.h>

struct Atleta {
    char nome[51];
    int gols;
};

struct Time {
    char nome[51];
    int qtAtletas;
    struct Atleta *atletas;
};

int mediaGolsTime(struct Atleta*, int);

int main() {

    struct Time *times;

    int N;

    scanf("%d", &N);

    times = (struct Time*)malloc(sizeof(struct Time) * N);

    for(int i = 0; i < N; i++) {
        scanf("%s", times[i].nome);
        scanf("%d", &times[i].qtAtletas);

        times[i].atletas = (struct Atleta*)malloc(sizeof(struct Atleta) * times[i].qtAtletas);

        for (int j = 0; j < times[i].qtAtletas; j++) {
            scanf("%s %d", &times[i].atletas[j].nome, &times[i].atletas[j].gols);
        }
    }

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < times[i].qtAtletas; j++) {

            if (times[i].atletas[j].gols > mediaGolsTime(times[i].atletas, times[i].qtAtletas)){

                printf("[%s] %s\n", times[i].nome, times[i].atletas[j].nome);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        free(times[i].atletas);
    }

    free(times);

    return 0;
}

int mediaGolsTime(struct Atleta *jogadores, int qtAtletas) {
    int soma = 0;

    for (int i = 0; i < qtAtletas; i++) {
        soma += jogadores[i].gols;
    }

    return soma / qtAtletas;
}