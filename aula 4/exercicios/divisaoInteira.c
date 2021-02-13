#include <stdio.h>

long int divisaoInteira(long int, long int, long int);

int main() {
    long int a, b;
    long int quoc = 0;
    scanf("%ld %ld", &a, &b);
    quoc = divisaoInteira(a, b, quoc);
    printf("%ld\n", quoc);
    return 0;
}

long int divisaoInteira(long int a, long int b, long int quoc) {
    if( a < b) {
        return quoc;
    }
    return divisaoInteira(a - b, b, ++quoc);
}

