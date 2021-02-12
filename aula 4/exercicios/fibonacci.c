#include <stdio.h>

int fibonacci(int);

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", fibonacci(n));
    return 0;
}

int fibonacci(int n) {
    int num = 0;
    int ant = 1;
    
    for (int i = 1; i < n; i++) {
        num = ant + num;
        ant = num - ant;
    }
    
    return num;
}