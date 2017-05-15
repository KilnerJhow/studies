#include <stdio.h>
#include <stdlib.h>

int checkPrimeNumber(int n, int limit3){
    
    int x = n, i = 0, di = 0;
    
    for(i = 1; i <= limit3; i++){
        if(x % i == 0){
            di++;
            
        }
        if(di > 2) break;
    }
    if(di == 2) {
        return 1;
    } else {
        return 0;
    }
}

void getPrimeNumbers(int limit1, int limit2){
    
    int limit = 0, i = 0, j = 0, aux = 0, dmax= 0, maior = 0;
    if(limit1 > limit2) {
        limit = limit1;
        aux = limit2;
    }
    else {
        limit = limit2;
        aux = limit1;
    }
    dmax = aux;
    aux = limit;
    for(i = limit; i >= dmax; i--){
        
        if (checkPrimeNumber(aux, limit) == 1) {
            
            printf(" %d, ", aux);
        }
        aux--;
    }
    
}

int main() {
    
    int x, y;
    scanf("%d %d", &x, &y);
    getPrimeNumbers(x, y);
    
    return 0;
}