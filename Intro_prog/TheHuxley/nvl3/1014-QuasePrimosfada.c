#include <stdio.h>

int checkPrimo(int numero) {
    
    int i, divisores = 1;
    for (i = 2; i <= numero && divisores < 3; i++) {
        if(!(numero % i)) {
            divisores++;
        }
        
    }
    if(divisores <= 2) return 0;
    return 1;
}


void ehPrimo(int numero) {
    
    if(numero == 1) {
        printf("Nem primo nem quase primo\n");
        return;
    } 
    int i, count = 2, divisores = 1, ultimoDivisor, quasePrimo = 0, aux;
    
    for(i = 0; i <= numero && divisores < 3; i++) {
        
        aux = divisores;
        if(!(numero % count)) {
            divisores++;
            if(numero == count*ultimoDivisor && !checkPrimo(count)) {
                quasePrimo = 1;
            }
        }
        if(aux != divisores) ultimoDivisor = count;
        count++;
        
    }

    
    if(divisores <= 2) {
        printf("Primo\n");
    } else if(quasePrimo) {
        printf("Quase primo\n");
    } else {
        printf("Nem primo nem quase primo\n");
    }
    
}


int main() {
    
    int qtdNumeros, numero;
    
    scanf("%d", &qtdNumeros);
    
    do{
        scanf("%d", &numero);
        ehPrimo(numero);
        
        qtdNumeros--;
    } while(qtdNumeros > 0);
    
    return 0;
}