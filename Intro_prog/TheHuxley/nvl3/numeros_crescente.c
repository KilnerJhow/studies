#include <stdio.h>
#include <stdlib.h>


int main(){
    
    int vet, j = 0, i = 0, aux = 0;

    do{
        scanf("%d", &vet);
        if( vet > aux ){
            aux = vet;
        }
        if(i >= 100) break;
        i++;
    } while (vet != 0);
 
    printf("%d", aux);

    return 0;
}