#include <stdio.h>

int main() {
    
    char tamanho;
    int qtd, count = 0, qtdCapsulas = 0;
    
    while (count < 7) {
        scanf(" %d", &qtd);
        scanf(" %c", &tamanho);
        
        if(tamanho == 'P' || tamanho == 'p') qtdCapsulas += qtd*10;
        else if(tamanho == 'G' || tamanho == 'g') qtdCapsulas += qtd*16;
        
        count++;
    }
    
    printf("%d\n%d\n", qtdCapsulas, (qtdCapsulas*2)/7);
    
    return 0;
}