#include <stdio.h>


int main() {
    
    int x,y, aux = 10;
    printf("Digite duas dezenas: ");
    scanf("%d%d", &x, &y);
    
    
    /*while(y >= aux) {
        aux *= 10;
    }*/
    
    
    int sum = x+y;
    if((sum*sum) == (x*aux + y)) {
        printf("True");
    } else {
        printf("False");
    }
    
    
}