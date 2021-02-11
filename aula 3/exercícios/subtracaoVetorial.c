#include <stdio.h>

int main() {
    int N;

    do {
        scanf("%d", &N);

        if(N != 0) {
            float v1[N], v2[N];
            for(int i = 0; i < N; i++) {
                scanf("%f", &v1[i]);
            }

            for(int i = 0; i < N; i++) {
                scanf("%f", &v2[i]);
            }

            for(int i = 0; i < N; i++) {
                if(i != N - 1) {
                    printf("%.2f ", v1[i] - v2[i]);
                } else {
                    printf("%.2f\n", v1[i] - v2[i]);
                }
            }
        }

    } while(N != 0);
}