#include <stdio.h>

int main() {
    
    int nMatriz;
    
    scanf("%d", &nMatriz);
    
    int matriz[nMatriz][nMatriz], linha = 0, coluna = 0, count = 0;
    int qtdElementos = nMatriz*nMatriz;
    int aux = 0, matrizN = nMatriz-1;
    
    while(count < qtdElementos) {
        
        scanf("%d", &matriz[linha][coluna]);
        
        //printf("Linha: %d, Coluna: %d = %d\n", linha, coluna, matriz[linha][coluna]);
        count++;
        
        if(linha != (matrizN - aux) && coluna == aux){
            //printf("Linha++\n");
            linha++;
        }
        else if(linha == (matrizN - aux) && coluna != (matrizN-aux)) {
            //printf("Coluna++\n");
            coluna++;
        }
        else if(coluna == (matrizN-aux) && linha != aux) {
            //printf("Linha--\n");
            linha--;
        }
        else if(linha == aux && coluna != (aux+1)) {
            //printf("Coluna--\n");
            coluna--;
        }
        else if(linha == aux && coluna == (aux+1)){
            //printf("Linha--\n");
            linha++;
            aux++;
        }
        
    }
    int i = 0, j = 0;
   
    while(i < nMatriz && j < nMatriz){
        
        printf("%d\n", matriz[i][j]);
        
        j++;
        if(j == nMatriz){
            j = 0;
            i++;
        }
        
    }
    
    return 0;
}