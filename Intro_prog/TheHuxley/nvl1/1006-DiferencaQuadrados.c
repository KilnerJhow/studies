#include <stdio.h>

//TODO: Use function to accelarate the resolution

void getQuadrados(int n) {
    
    int quadradoMaior = 0, quadradoMenor = 0;
    int sum = 0, aux = 0;
    /*do {
        if(sum != n) {
            quadradoMaior++;
        }
        quadradoMenor = quadradoMaior - 1;
        sum = quadradoMaior + quadradoMenor;
    } while(sum != n);*/
    aux = 0.5*n - 0.5;
    
    quadradoMaior = n - aux;
    quadradoMenor = aux;
    //printf("Aux = %d QM = %d Qm = %d\n", aux, quadradoMaior, quadradoMenor);
    printf("%d - %d\n", quadradoMaior*quadradoMaior, quadradoMenor*quadradoMenor);
    
}


int main() {
    
    int x, quadradoMenor = 0, quadradoMaior = 0;
    scanf("%d", &x);
    
    do{
        getQuadrados(x);
        
        scanf("%d", &x);
    } while( x != 0 );
    
    
    return 0;
}