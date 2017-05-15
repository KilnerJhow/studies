#include <stdio.h>


int main() {
    
    int estoque, vendaSQ, semanas, SE, SA, DO, aux = 0;
    int estoqueInicial;
    scanf("%d\n%d\n%d", &estoque, &vendaSQ, &semanas);

    do{
        scanf("%d %d %d", &SE, &SA, &DO);
        estoque -= 4*vendaSQ; 
        estoque -= (SE + SA + DO);
        aux++;

    } while(aux < semanas && estoque > 0);
    if(estoque > 0) printf("%d\n", estoque);
    else printf("%d %d\n", aux, estoque);
    
    return 0;
}