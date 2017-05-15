#include <stdio.h>

int main() {
    
    int x = 0, maior = 0, medio = 0, menor = 0;
    scanf("%d%d%d", &maior, &medio, &menor);
    
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
    
    printf("%d\n%d\n%d", maior, medio, menor);
    return 0;
}