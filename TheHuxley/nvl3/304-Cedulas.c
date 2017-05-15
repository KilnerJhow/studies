#include <stdio.h>

int main() {
    
    int notas[7], valorRecebido, aux = 0, valorMostrado, i;
    notas[0] = 100; notas[1] = 50; notas[2] = 20;
    notas[3] = 10; notas[4] = 5; notas[5] = 2; notas[6] = 1;
    
    scanf("%d", &valorRecebido);
    valorMostrado = valorRecebido;
    printf("%d\n", valorMostrado);
    for(i = 0; i < 7; i++) {
        
        while(valorRecebido >= notas[i]) {
            valorRecebido -= notas[i];
            aux++;
        }
        
        printf("%d nota(s) de R$ %d,00\n", aux, notas[i]);
        
        aux = 0;
        
    }
    
}