#include <stdio.h>

#define MAX 3


int main() {
    
    int arr[MAX], i;
    
   for(i = 0; i < MAX; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (i = 0; i < MAX; i++) {
        int temp, j;
        
        for(j = 0; j < MAX; j++) {
            if(arr[j] > arr[i]) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
        
    }
    
    for(i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
    
    
}