#include <stdio.h>

int getSomaNumTriangulares(int numeroTriangular) {
    
    int soma = 0, aux = numeroTriangular;
    
    do{
        soma += (numeroTriangular*(numeroTriangular + 1))/2;
        numeroTriangular--;
        
    } while(numeroTriangular > 0);
    
    return soma;
}


int main() {
    
    int soma = 0, numeroTriangular, paridadeSoma, paridadeNumero;
    
    scanf("%d", &numeroTriangular);
    
    soma = getSomaNumTriangulares(numeroTriangular - 1);
    numeroTriangular = (numeroTriangular*(numeroTriangular + 1))/2;
    soma += numeroTriangular;
    
    paridadeNumero = numeroTriangular%2;
    paridadeSoma = soma%2;
    
    printf("%d %d ", numeroTriangular, soma);
    
    if( paridadeNumero && paridadeSoma ) {
        printf("I\n");
    } else if( !paridadeNumero && !paridadeSoma ) {
        printf("P\n");
    } else {
        printf("N\n");
    }

    
    return 0;
}