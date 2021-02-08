#include <stdio.h>
#include <math.h>

int eq2Plus(float*, float*, float*);

int main() {
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    int r = eq2Plus(&a, &b, &c);

    if(r == 0) {
        printf("nao ha raiz real");
    } else if(r == 1) {
        printf("%.4f", a);
    } else {
        printf("%.4f %.4f", a, b);
    }
    return 0;
}

int eq2Plus(float* a, float* b, float* c) {
    float delta = pow(*b, 2) - (4 * *a * *c);

    if(delta < 0) {
        return 0;
    } else {
        float x1 = (-*b + sqrt(delta)) / (2 * *a);
        float x2 = (-*b - sqrt(delta)) / (2 * *a);

        if(x1 == x2) {
            *a = x1;
            return 1;
        } else {
            *a = x1;
            *b = x2;
            return 2;
        }
    }

}