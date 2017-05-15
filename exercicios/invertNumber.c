#include <stdio.h>


int main() {
    
    int x = 0, aux = 0;
    
    printf("Digite um valor entre 1000 e 9999: ");
    scanf("%d", &x);
    
    do {
        system("clear");
        printf("Valor invalido, digite novamente: ");
        scanf("%d", &x);
        
    }while(x < 1000 || x > 9999);
    
    aux = (x/1000) + ((x%1000 - x%100)/100)*10 + ((x%100 - x%10)/10)*100 + (x%10)*1000;
    
    if (aux == x) {
        printf("Verdade");
    } else {
        printf("Falso");
    }
    
    return 0;
}