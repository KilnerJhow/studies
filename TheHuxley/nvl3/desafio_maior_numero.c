#include <stdio.h>
#include <stdlib.h>


int main(){
    
    int i = 0;
    double aux, valor;
    while (i < 3){
        scanf("%lf", &valor);
        if( valor > aux ){
            aux = valor;
        }
        i++;
    }
    
 
    printf("%d", aux);

    return 0;
}