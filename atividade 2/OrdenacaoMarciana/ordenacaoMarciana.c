#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int ordenaBubble(int *, int);

int main() {

    int n;

    scanf("%d", &n);

    int *v = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    ordenacaoMarciana(v, n);

    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], (i < n - 1 ? " " : "\n"));
    }

    free(v);

    return 0;
}

void ordenacaoMarciana(int *v, int n) {
    
}

bool comparador(int *v, int p1, int p2) {
    if (p1 == 0) {
        if (p2 == 1) {

            return false;

        } else if( p2 == 2) {

            return false;

        } else if( p2 == 3) {

            return false;
            
        } else if( p2 == 4) {

            return false;
            
        } else if( p2 == 5) {

            return false;
            
        } else if( p2 == 6) {

            return false;
            
        } else if( p2 == 7) {

            return false;
            
        } else if( p2 == 8) {

            return false;
            
        } else {

            return false;
            
        } 

    } else if (p1 == 1) {
        if (p2 == 1) {

        } else if( p2 == 2) {

        } else if( p2 == 3) {
            
        } else if( p2 == 4) {
            
        } else if( p2 == 5) {
            
        } else if( p2 == 6) {
            
        } else if( p2 == 7) {
            
        } else if( p2 == 8) {
            
        } else {
            
        }

    } else if (p1 == 2) {

        if (p2 == 1) {

        } else if( p2 == 2) {

        } else if( p2 == 3) {
            
        } else if( p2 == 4) {
            
        } else if( p2 == 5) {
            
        } else if( p2 == 6) {
            
        } else if( p2 == 7) {
            
        } else if( p2 == 8) {
            
        } else {
            
        }
        
    } else if (p1 == 3) {

        if (p2 == 1) {

        } else if( p2 == 2) {

        } else if( p2 == 3) {
            
        } else if( p2 == 4) {
            
        } else if( p2 == 5) {
            
        } else if( p2 == 6) {
            
        } else if( p2 == 7) {
            
        } else if( p2 == 8) {
            
        } else {
            
        }
        
    } else if (p1 == 4) {

        if (p2 == 1) {

        } else if( p2 == 2) {

        } else if( p2 == 3) {
            
        } else if( p2 == 4) {
            
        } else if( p2 == 5) {
            
        } else if( p2 == 6) {
            
        } else if( p2 == 7) {
            
        } else if( p2 == 8) {
            
        } else {
            
        }
        
    } else if (p1 == 5) {

        if (p2 == 1) {

        } else if( p2 == 2) {

        } else if( p2 == 3) {
            
        } else if( p2 == 4) {
            
        } else if( p2 == 5) {
            
        } else if( p2 == 6) {
            
        } else if( p2 == 7) {
            
        } else if( p2 == 8) {
            
        } else {
            
        }
        
    } else if (p1 == 6) {

        if (p2 == 1) {

        } else if( p2 == 2) {

        } else if( p2 == 3) {
            
        } else if( p2 == 4) {
            
        } else if( p2 == 5) {
            
        } else if( p2 == 6) {
            
        } else if( p2 == 7) {
            
        } else if( p2 == 8) {
            
        } else {
            
        }
        
    } else if (p1 == 7) {

        if (p2 == 1) {

        } else if( p2 == 2) {

        } else if( p2 == 3) {
            
        } else if( p2 == 4) {
            
        } else if( p2 == 5) {
            
        } else if( p2 == 6) {
            
        } else if( p2 == 7) {
            
        } else if( p2 == 8) {
            
        } else {
            
        }
        
    } else if (p1 == 8) {

        if (p2 == 1) {

        } else if( p2 == 2) {

        } else if( p2 == 3) {
            
        } else if( p2 == 4) {
            
        } else if( p2 == 5) {
            
        } else if( p2 == 6) {
            
        } else if( p2 == 7) {
            
        } else if( p2 == 8) {
            
        } else {
            
        }
        
    } else {

        if (p2 == 1) {

        } else if( p2 == 2) {

        } else if( p2 == 3) {
            
        } else if( p2 == 4) {
            
        } else if( p2 == 5) {
            
        } else if( p2 == 6) {
            
        } else if( p2 == 7) {
            
        } else if( p2 == 8) {
            
        } else {
            
        }

    }
}