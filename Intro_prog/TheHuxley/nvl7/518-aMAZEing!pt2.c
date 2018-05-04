#include <stdio.h>

int tamanhoArray;

void calculaCaso(int posicao){
    
    int arrayLabirinto[tamanhoArray][tamanhoArray], i, j, aux = 0;
    int totalParede = (2*(tamanhoArray*tamanhoArray - tamanhoArray) - 1);
    int forcaParede[totalParede];
    
    
    for(i = 0; i < tamanhoArray; i++) {
        
        for(j = 0; j < tamanhoArray; j++){
            arrayLabirinto[i][j] = aux;
            aux++;
        }
        
    }
    
    for(i = 0; i < totalParede; i++) {
        scanf("%d", forcaParede[i]);
    }
    
    
    
}

int main() {
    
    int posicaoX;
    scanf("%d %d", &tamanhoArray, &posicaoX);
    calculaCaso(posicaoX);
    
    
}