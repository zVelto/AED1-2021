#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    int N = (rand()%10001);

    printf("%d\n", N);

    for (int i = 0; i < N; i++) {
        printf("%d%s", rand(), ( i < N - 1 ? " " : "\n"));
    }

    return 0;
}