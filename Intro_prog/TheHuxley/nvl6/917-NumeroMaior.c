#include <stdio.h>

int main() {
    
    float maior, menor, medio, x;
    printf("Digite um numero:\n");
    scanf("%f%", &maior);
    printf("Digite outro numero:\n");
    scanf("%f%", &medio);
    printf("Digite outro numero:\n");
    scanf("%f%", &menor);
    if(maior <= medio || maior <= menor || medio <= menor) {
        
        if(maior <= menor) {
            x = maior;
            maior = menor;
            menor = x;
        }
        if(maior <= medio){
            x = maior;
            maior = medio;
            medio = x;
        }
        if(medio <= menor) {
            x = medio;
            medio = menor;
            menor = x;
        } 
    } 
    printf("Maior numero: %.1f", maior);
    return 0;
}