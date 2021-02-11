#include <stdio.h>

int main() {
    int v[] = {1, 1, 2, 3, 5, 8 ,13, 21 ,34, 55}, i;
    printf("v[0]: %d\n", v[0]);
    printf("v[1]: %d\n", v[1]);
    printf("v[2]: %d\n", v[2]);
    printf("v[3]: %d\n", v[3]);
    printf("v[5]: %d\n", v[5]);
    printf("v[8]: %d\n", v[8]);
    printf("v[9]: %d\n", v[9]);
    printf("v: %p\n", v);
    printf("*v: %d\n", *v);
    printf("&v[0]: %p\n", &v[0]);
    printf("&v[1]: %p\n", &v[1]);
    printf("&v[2]: %p\n", &v[2]);
    printf("*v[1]: %d\n", *&v[1]);
    printf("*v[2]: %d\n", *&v[2]);
    printf("*v[3]: %d\n", *&v[3]);

    printf("&v : %p\n", &v);
    printf("(&v)+1: %p\n", (&v)+1);

    printf("*v: %d - v: %p\n", *v, v);
    printf("*v+1: %d - v: %p\n", *(v+1), v+1);
    printf("*v+2: %d - v: %p\n", *(v+2), v+2);
    printf("*v+3: %d - v: %p\n", *(v+3), v+3);
    printf("*v+4: %d - v: %p\n", *(v+4), v+4);

    for(i = 0; i < 10; i++) {
        printf("v+%d : %p - *v+%d : %d\n", i, v+i, i, *(v+i));
    }

    return 0;
}