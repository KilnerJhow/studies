#include <stdio.h>

int main() {
    
    double x;
    printf("Informe a medida de um dos lados do quadrado:\n");
    scanf("%lf", &x);
    printf("Resultado: %.1lf\n", x*x);
    printf("Dobro: %.1lf\n", x*x*2);
    
    return 0;
}