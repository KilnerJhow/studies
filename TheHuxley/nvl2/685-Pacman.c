#include <stdio.h>

int main() {
    
    int nMatriz;
    scanf(" %d", &nMatriz);
    char arr[nMatriz][nMatriz];
    int linha = 0, coluna = 0, count = 0, maiorValor = 0, aux = 0, sentido = 0, i = 0;
    
    for(linha = 0; linha < nMatriz; linha++) {
        
        for(coluna = 0; coluna < nMatriz; coluna++) {
            scanf(" %c", &arr[linha][coluna]);
            //printf(" %c ", arr[linha][coluna]);
        }
        //printf("\n");
    }
    
    
    int qtdElementos = nMatriz*nMatriz;
    linha = 0;
    coluna = 0;
    for(i = 0; i < qtdElementos; i++) {
        
        if(arr[linha][coluna] == 'o') {
            count++;
            if(count > maiorValor) maiorValor = count;
        }
        else if(arr[linha][coluna] == 'A') {
            count = 0;
            //printf("A - Linha: %d Coluna: %d\n", linha, coluna);
        }
        
        if(coluna == (nMatriz-1) && !aux) {
            sentido = 1;
            linha++;
            aux = 1;
        } else if(coluna == 0 && aux) {
            sentido = 0;
            linha++;
            aux = 0;
        } else {
            if(sentido) coluna--;
            else coluna++;
        }
        //printf("Linha: %d Coluna: %d\n", linha, coluna);
    }
    
    printf("%d\n", maiorValor);
    
    
    return 0;
}