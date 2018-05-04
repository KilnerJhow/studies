#include <stdio.h>

int main() {
    
    double temperatura;
    printf("Digite uma temperatura na escala Fahrenheit:\n");
    
    scanf("%lf", &temperatura);
    temperatura = (5*(temperatura-32))/9;
    printf("Temperatura em Celsius: %.1lf", temperatura);
    
    return 0;
}