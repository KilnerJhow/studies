#include <stdio.h>

int main() {
    
    int maior, menor, medio, x;
    scanf("%d%d%d", &maior, &menor, &medio);
    
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
    printf("%d", menor);
    return 0;
}