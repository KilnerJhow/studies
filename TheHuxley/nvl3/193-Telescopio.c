#include <stdio.h>

int main() {
    
    int areaTelescopio, fluxoFotons, qtdEstrelas, qtdEstrelasObservadas = 0;
    int fluxoFotonPercepcao = 40000000;
    
    scanf("%d", &areaTelescopio);
    scanf("%d", &qtdEstrelas);
     
    do {
        scanf("%d", &fluxoFotons);
        
        if(areaTelescopio*fluxoFotons >= fluxoFotonPercepcao) qtdEstrelasObservadas++;
        
        qtdEstrelas--;
    } while(qtdEstrelas > 0);
    
    printf("%d\n", qtdEstrelasObservadas);
    
    return 0;
}