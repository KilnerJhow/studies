#include <stdio.h>


int main() {
    
    int x = 0, count = 0;
    double a;
    do {
        printf("Digite um valor:\n");
        scanf("%lf", &a);
        if(a < 0) x++;
        count++;
    } while(count < 5);
    printf("Foram digitados %d numeros negativos\n", x);
    
    return 0;
}