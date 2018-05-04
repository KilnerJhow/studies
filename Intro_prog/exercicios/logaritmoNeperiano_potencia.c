#include <stdio.h>

int main() {
    
    int n = 0;
    int  aux = 1, y = -1;
    float sum = 0, x = 0, w = 0, var = 0, aux1 = 0;
    
    printf("Digite um numero para a potencia de ln (máximo 0.99): ");
    scanf("%f", &x);
    if(x >= 1) {
        do {
            printf("Digite um valor válido para x: ");
            scanf("%f", &x);
        } while( x >= 1 );
    }
    
    w = x;
 
    for(n = 0; n <= 20; n++) {
        
        
        if(n % 2 == 0 || n == 0) y = 1;
        else y = -1;
        
        
        if(n == 0) {
            sum = x;
        } else {
            x*=w;
            var = ((float)y/(float)(n+1)) * x;
            sum = sum + var;
        }
        
        /*
        printf("Valor soma: %f\n", sum);
        printf("Valor y: %d\n", y);
        printf("Valor n: %d\n", n);
        printf("Valor x: %f\n", x);
        printf("Valor var: %f\n", var);
        printf("\nEnd\n");
        */
        
    }
    printf("Numero gerado: %f", sum);
    
}