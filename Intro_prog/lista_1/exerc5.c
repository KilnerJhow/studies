#include <stdio.h>
#include <stdlib.h>



int main () {
    
    int x, y, z;
    
    printf("Digite tres numeros: ");
    scanf("%d %d %d", &x, &y, &z);
    
    if(x >= y + z || y >= x + z || z >= x + y){
        printf("True");
    } else {
        printf("False");
    }
    
    
    return 0;
}