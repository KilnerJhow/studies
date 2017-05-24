#include <stdio.h>

void swap(int *a, int*b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void printArray(int arr[], int count) {
    int i;
    
    for(i = 0; i < count; i++) {
        if(i == count-1) printf("%d", arr[i]);
        else printf("%d | ", arr[i]);
    }
    printf("\n");
    //("\n");
}

void selectionSort(int arr[], int count) {
    
    int i, j, posicao = 0, posicaoElemento = 0;
    int count2 = count - 1;
    for(i = 0; i < count2; i++) {
        posicaoElemento = i;
        for(j = i; j < count; j++) {
                if(arr[j] < arr[posicaoElemento]) posicaoElemento = j;
        }
        printf("Menor elemento neste passo: %d\n", arr[posicaoElemento]);
        swap(&arr[i], &arr[posicaoElemento]);
        printf("Estado Atual: ");
        printArray(arr, count);
        printf("\n");
        //printf("I: %d Menor: %d Posicao: %d\n\n",i, menor, posicao);
    }
    printf("Resultado Final: ");
    printArray(arr, count);
    printf("\n");
}


int main() {
    
    int x, y, count = 0;
    int array[200];
    
    
    while(scanf("%d", &x) != EOF) {
        
        array[count] = x;
        count++;
        
    }
    //printf("Count: %d\n", count);
    //printArray(array, count);
    selectionSort(array, count);
    
    return 0;
}