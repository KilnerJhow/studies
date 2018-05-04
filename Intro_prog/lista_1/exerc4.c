#include <stdio.h>
#include <stdlib.h>



int main() {
    
    int x, y;
    
    printf("Digite dois numeros: ");
    
    scanf("%d %d", &x, &y);
    
    if(x % y == 0 || y % x == 0) {
        printf("true\n");
    } 
    
}