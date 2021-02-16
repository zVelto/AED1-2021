#include <stdio.h>

int adicao(int, int);

int main() {

    int A, B;

    scanf("%d %d", &A, &B);

    printf("%d\n", adicao(A, B));

    return 0;
}

int adicao(int A, int B) {
    if(B == 0) {
        return A;
    } else {
        return 1 + adicao(A, B - 1);
    }
}