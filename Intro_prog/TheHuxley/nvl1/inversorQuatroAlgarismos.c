#include <stdio.h>


int main() {
    
    int x = 0, aux = 0;
    scanf("%d", &x);

    aux = (x/1000) + ((x%1000 - x%100)/10) + ((x%100 - x%10))*10 + (x%10)*1000;
    
    printf("%d", aux);
    
    return 0;
}