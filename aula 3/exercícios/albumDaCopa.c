#include <stdio.h>
#include <stdlib.h>

int main() {
    int v1[3];

    scanf("%d %d %d", &v1[0], &v1[1], &v1[2]);

    int* v2 = (int*)malloc(sizeof(int*) * v1[1]);
    int* v3 = (int*)malloc(sizeof(int*) * v1[2]);
    int figFaltantes = v1[1];

    for (int i = 0; i < v1[1]; i++) {
        scanf("%d", &v2[i]);
    }

    for (int i = 0; i < v1[2]; i++) {
        scanf("%d", &v3[i]);
    }

    for (int i = 0; i < v1[1]; i++) {
        for(int j = 0; j < v1[2]; j++) {
            if(v2[i] == v3[j]) {
                figFaltantes--;
                break;
            }
        }
    }

    printf("%d\n", figFaltantes);
}