#include <stdio.h>

void fatorial(int n) {
    int i;
    if (n <= 0) n = 1;
    else {
        for(i = n-1; i > 1; i--) {
            n *= i;
        }
    }   
    printf("%d\n", n);
}

int main() {
    
    int x;
    do {
        scanf("%d", &x);
        if(x != -1) fatorial(x);
    } while (x != -1);
}