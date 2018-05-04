#include <stdio.h>

void swap(int *a, int*b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void printArray(int array[], int count) {
    int i;
    for(i = 0; i < count; i++) {
            if(i == (count-1)) printf("%d", array[i]);
            else printf("%d | ", array[i]);
        }
    printf("\n");
}

void insertionSort(int array[], int count) {
    
    int i, j, chave = array[1], aux = 1;
    
    for(i = 0; i < (count - 1); i++) {
        printf("Chave: %d\n", chave);
        printf("Estado Atual: ");
        printArray(array, count);
        for(j = aux; j >= 1; j--) {
            if(array[j-1] > chave) {
                swap(&array[j-1], &array[j]);
                printArray(array, count);
            }
        }
        printf("\n");
        aux++;
        chave = array[aux];
        
    }
    
    printf("Resultado Final: ");
    printArray(array, count);
    
    
}

int main() {
    
    int x, y, count = 0;
    int array[400];
    
    
    while(scanf("%d", &x) != EOF) {
        
        array[count] = x;
        count++;
        
    }
    //printf("Count: %d\n", count);
    insertionSort(array, count);

    
    return 0;
}