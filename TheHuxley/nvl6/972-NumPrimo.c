#include <stdio.h>

int calculeNumPrimo(int x) {
    int i = 0, aux = 1, y = 2;
    if(x == 1) return 0;
    while(i < 1000) {
        if(x % y == 0) aux++;
        if(aux > 3) break;
        y++;
        i++;
    }
    if(aux == 2) return 1;
    else return 0;
}

int main() {
    
    int number, y = 2, aux = 1;
    do{
        scanf("%d", &number);
        if(number != -1) {
            aux = calculeNumPrimo(number);
            printf("%d\n", aux);
        }
        
    } while( number != -1);
    
    return 0;
}