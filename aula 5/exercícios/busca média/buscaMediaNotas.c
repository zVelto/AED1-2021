#include <stdio.h>
#include <stdlib.h>

struct Aluno {
    char nome[101];
    char matricula[12];
    int qtNotas;
    int *notas;
};

int MediaAluno(int*, int);

int main() {

    struct Aluno *turma;

    int N, media;

    scanf("%d", &N);

    turma = (struct Aluno*)malloc(sizeof(struct Aluno) * N);

    for(int i = 0; i < N; i++) {
        scanf("%s", turma[i].nome);
        scanf("%s", turma[i].matricula);
        scanf("%d", &turma[i].qtNotas);

        turma[i].notas = (int*)malloc(sizeof(int*) * turma[i].qtNotas);

        for (int j = 0; j < turma[i].qtNotas; j++) {
            scanf("%d", &turma[i].notas[j]);
        }
    }

    scanf("%d", &media);

    for (int i = 0; i < N; i++) {
        if (MediaAluno(turma[i].notas, turma[i].qtNotas) == media){

            printf("[%s] %s\n", turma[i].matricula, turma[i].nome);
        }
    }

    free(turma);

    return 0;
}

int MediaAluno(int *v, int n) {
    int soma = 0;

    for (int i = 0; i < n; i++) {
        soma += v[i];
    }

    return soma / n;
}