#include <stdio.h>

#define TAM_MAX 5

void ordenacao(int array[]) {
    
    int i = 0, aux = 0, count = 0;
    for(; i < TAM_MAX; i++) {
        
        if(array[i] > aux) {
            aux = array[i];
            count++;
        }
    }
    
    if(count == 5) printf("C");
    else if(count == 1) printf("D");
    else printf("N");
    
}

int main() {
    
    int cartas[5], aux = 0;
    
    do{
        scanf("%d", &cartas[aux]);
        aux++;
    } while(aux < TAM_MAX);
    
    ordenacao(cartas);
    
    return 0;
}