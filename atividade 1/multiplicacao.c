#include <stdio.h>

long int multiplicacao(long int, long int);

int main() {

    long int A, B;

    scanf("%ld %ld", &A, &B);

    printf("%ld\n", multiplicacao(A, B));

    return 0;
}

long int multiplicacao(long int A, long int B) {
    if(B == 0) {
        return 0;
    } else {
        return A + multiplicacao(A, --B);
    }
}