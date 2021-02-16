#include <stdio.h>

long int catalan(long int);

int main() {
    long int N;

    scanf("%ld", &N);

    while(N != -1) {

        printf("%ld\n", catalan(N));

        scanf("%ld", &N);

    }

    return 0;
}

long int catalan (long int N) {
    if(N == 0) {
        return 1;
    } else {
        return ((4 * N - 2) * catalan(N - 1)/ (N + 1));
    }
}