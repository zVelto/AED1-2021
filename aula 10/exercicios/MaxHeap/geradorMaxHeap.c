#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    int contas = (rand()%11);

    for( int i = 0; i < contas; i++) {

        int n = (rand()%100) + 1;

        printf("%d\n", n);

        for(int j = 0; j < n; j++) {
            printf("%d%s", rand()%101, (j < n - 1 ? " " : "\n"));
        }
    }

    printf("%d\n", 0);

    return 0;
}