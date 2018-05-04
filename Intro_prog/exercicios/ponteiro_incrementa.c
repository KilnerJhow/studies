#include <stdio.h>


void inc(int* i, const int increment) {

    *i += increment;    
}

int main() {
    
    int x = 0, c = 2;
    inc(&x, c);
    
    printf("%d\n", x);
    
    return 0;
}