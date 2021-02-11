#include <stdio.h>

int main() {

    int N;

    scanf("%d", &N);

    int v[N];

    for(int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
        v[i] = v[i] * 3;
    }

    for (int i = 0; i < N; i++) {
        if(i != N - 1) {
            printf("%d ", v[i]);
        } else {
            printf("%d\n", v[i]);
        }
    }
    
    return 0;
}