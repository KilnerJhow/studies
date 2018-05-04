#include <stdio.h>


int main() {
    
    int qtdLigacoes = 0, franquiaMinuto = 40, somaMinutos = 0, aux, franquiaAtingida = 0;
    double valorInicial = 10, valorMinuto = 0.2, valorFinal = 0;
    
    do {
        scanf("%d", &aux);
        somaMinutos += aux;
        
        if(qtdLigacoes != 10 && !franquiaAtingida) {
            qtdLigacoes++;
            if(qtdLigacoes == 10) somaMinutos = 0;
        }
        
        if(somaMinutos >= 40 && qtdLigacoes < 10) {
            franquiaAtingida = 1;
        }
        
    } while(aux != 0);
    
    if(qtdLigacoes == 10 || franquiaAtingida) {
        
        if(franquiaAtingida) {
            valorFinal = (somaMinutos - franquiaMinuto)*valorMinuto + valorInicial;
        } else {
            valorFinal = somaMinutos*valorMinuto + valorInicial;
        }
        printf("%.2lf\n", valorFinal);
        
    } else {
        printf("%.2lf\n", valorInicial);
    }
    
    return 0;
}