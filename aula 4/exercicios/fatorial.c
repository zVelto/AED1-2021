#include <stdio.h>

long long int fatorial(long long int);

int main() {
    long long int n;
    scanf("%lld", &n);
    printf("%lld\n", fatorial(n));
    return 0;
}

long long int fatorial(long long int n) {
    if(n == 0) {
        return 1;
    }
    return n * fatorial(n - 1);
}