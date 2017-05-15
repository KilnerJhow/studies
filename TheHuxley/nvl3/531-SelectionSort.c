#include <stdio.h>

void swap(int *a, int*b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionSort(int array[], int count) {
    
    int i, j, aux = 0, aux2, menor = array[0];
    for(j = 0; j < (count-1); j++) {
        for(i = aux; i < count; i++) {
            
            if( menor > array[i] ) {
                menor = array[i];
                aux2 = i;
                
            }
            
        }
        
        if(array[aux] > array[aux2]) swap(&array[aux], &array[aux2]);
        aux++;
        printf("Menor elemento neste passo: %d\n", menor);
        printf("Estado Atual:");
        
        for(i = 0; i < count; i++) {
            if(i == (count-1)) printf(" %d", array[i]);
            else printf(" %d |", array[i]);
        }
        printf("\n\n");
        menor = array[aux];
    }
    
    printf("Resultado Final:");
    for(i = 0; i < count; i++) {
        if(i == (count-1)) printf(" %d", array[i]);
        else printf(" %d |", array[i]);
    }
    printf("\n\n");
    
}


int main() {
    
    int x, y, count = 0;
    int array[200];
    
    
    while(scanf("%d", &x) != EOF) {
        
        array[count] = x;
        count++;
        
    }
    
    selectionSort(array, count);
    
    return 0;
}