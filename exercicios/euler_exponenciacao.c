#include <stdio.h>

int main() {
    
    float n = 0, aux = 1, w = 0;
    double sum = 0, y = 1, x = 0;
  
    
    printf("Digite um numero para a potencia de 'e': ");
    scanf("%lf", &x);

    w = x;
    for(n = 0; n < 100; n++) {
        if(n == 0) {
            sum = 1;
            aux++;
        } else {
            sum += x/y;
            y *= aux;
            x *= w;
            aux++;
        }
        
    }
    printf("Numero gerado: %lf", sum);
    
}