#include <stdio.h>

int main() {
    
    int num, aux;
    
    scanf("%d", &num);
    aux = (num - (num%10))/10;
    if(num >= 10 || num <= 100) {
        if((num%10) == 0 || num%aux != 0) printf("NAO");
        else printf("SIM");
        
    }
    
    return 0;
}