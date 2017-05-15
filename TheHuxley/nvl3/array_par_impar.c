#include <stdio.h>

void printArray(int arr[], int k, int n) {
    
    int x = 0;
    if(n == 0) {
        for( x = 0; x < k; x++) {
            printf("par[%d] = %d\n", x, arr[x]);
            arr[x] = 0;
        }
    } else {
        for( x = 0; x < k; x++) {
            printf("impar[%d] = %d\n", x, arr[x]);
            arr[x] = 0;
        }
    }
}

int main() {
    
    int par[5], impar[5], i = 0, j = 0, aux = 0, x = 0;
    
    while(aux < 15) {
        
        scanf("%d", &x);
        if(x % 2 == 0) {
            if(i == 5) {
                printArray(par, i, 0); //0 for par, 1 for impar
                i = 0;
            }
            par[i] = x;
            i++;
        } else {
            if(j == 5){
                printArray(impar, j, 1);
                j = 0;
            } 
            impar[j] = x;
            j++;
        }
        
        
        aux++;
    }
    printArray(impar, j, 1);
    printArray(par, i, 0);
    return 0;
}