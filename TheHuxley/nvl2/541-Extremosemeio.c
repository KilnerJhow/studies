#include <stdio.h>

void swap(int *a, int*b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void insertionSort(int array[], int limit) {
    
    int i, j, chave = array[1], aux = 1;
    
    for(i = 0; i < (limit - 1); i++) {
        for(j = aux; j >= 1; j--) {
            if(array[j-1] > chave) {
                swap(&array[j-1], &array[j]);
            }
        }
        aux++;
        chave = array[aux];
    }
}

void selectionSort() {
    
    
    
}


int main() {
    
    int tamanhoArray;
    scanf("%d", &tamanhoArray);
    
    int arr[tamanhoArray];
    int i;
    
    for(i = 0; i < tamanhoArray; i++) {
        scanf(" %d", &arr[i]);
    }
    
    insertionSort(arr, tamanhoArray);
    
    int extremoInicio = arr[0], extremoFim = arr[tamanhoArray-1], extremoMeio = arr[tamanhoArray/2];
    
    printf("%d %d %d\n", extremoInicio, extremoMeio, extremoFim);
    
    return 0;
}