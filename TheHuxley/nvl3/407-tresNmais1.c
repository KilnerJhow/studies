#include <stdio.h>




int main() {
    
    int i, j, maior, menor;
    int maiorValor = 0, count = 1, aux = 0, temp;
    
    while( scanf("%d%d", &i, &j) != EOF) {
        
        if(i > j) {
            maior = i;
            menor = j;
        } else {
            maior = j;
            menor = i;
        }
        
        temp = maior;
        
        while( temp >= menor ) {
            aux = temp--;
            while(aux > 1) {
                
                if(aux % 2 == 0) aux /= 2;
                else aux = aux*3 + 1;
                count ++;
                
            }
            if(count > maiorValor) maiorValor = count;
            count = 1;
            
        }
        printf("%d %d %d\n", i, j, maiorValor);
        maiorValor = 0, count = 1;
    }
    
    return 0;
}