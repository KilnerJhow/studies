#include <stdio.h>

int main() {
    
    int x;
    double valor;
    scanf("%d", &x);
    x = 42 - x;
    valor = x*1.75;
    printf("%.2lf", valor);
    
    return 0;
}