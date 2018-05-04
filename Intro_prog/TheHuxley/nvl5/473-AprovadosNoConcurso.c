#include <stdio.h>

int main() {
    
    int notaPt = 1, notaMat, qtdPassados = 0;
    float notaRedacao;
    
    while(notaPt > 0) {
        scanf("%d", &notaPt);
        scanf("%d", &notaMat);
        scanf("%f", &notaRedacao);
        
        if(notaPt >= 40 && notaMat >= 21 && notaRedacao >= 7.0) qtdPassados++;
    }
    
    printf("%d\n", qtdPassados);
    
    return 0;
}