#include <stdio.h>

int getQtdAnoBissexto(int anoInicial, int anoFinal) {
    
    int a = anoFinal, b = anoInicial;
    
    int count = (a/4 - (b-1)/4) + (a/400 - (b-1)/400) - (a/100 - (b-1)/100);
    
    return count;
}


int main() {
    
    int anoInicial, anoFinal, anosN;
    
    scanf("%d %d", &anoInicial, &anoFinal);
    
    
    int anos = getQtdAnoBissexto(anoInicial+1, anoFinal-1);
    
    anosN = (anoFinal)-(anoInicial) -anos;

    printf("qtd anos: %d\n", anos);
    printf("Qtd anos total: %d\n", anoFinal - anoInicial);
    printf("Qtd anos n bissextos: %d\n", anosN);
    
    int qtdDias = anosN*365 + anos*366;
    
    printf("Qtd de dias: %d\n", qtdDias);

    return 0;
}