#include <stdio.h>
#include <math.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%lld\n", (long long int)pow(a, b));
    return 0;
}

