#include <stdio.h>
#include <stdlib.h>

int swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int getQtdAnoBissexto(int anoInicial, int anoFinal) {
    
    int a = anoFinal, b = anoInicial;
    
    int count = (a/4 - (b-1)/4) + (a/400 - (b-1)/400) - (a/100 - (b-1)/100);
    
    return count;
}


int checkAnoBissexto(int ano) {
    int x = ano;
    if(x % 4 == 0 && x % 100 != 0 || x%400 == 0) {
            return 1;
    } 
    return 0;
}



int main() {

    int diaInicial, mesInicial, anoInicial;
    int diaFinal, mesFinal, anoFinal;
    int qtdAnosBissextos, qtdDias = 0, total = 0, qtdAnosNBissextos = 0, aux = 0;
    
    int mes_final[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int mes_inicial[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    scanf("%d/%d/%d", &diaInicial, &mesInicial, &anoInicial);
    scanf("%d/%d/%d", &diaFinal, &mesFinal, &anoFinal);
    
    if(anoInicial > anoFinal) {
        swap(&anoInicial, &anoFinal);
        swap(&mesFinal, &mesInicial);
        swap(&diaInicial, &diaFinal);
    } else if(anoInicial == anoFinal && mesFinal < mesInicial) {
        swap(&mesFinal, &mesInicial);
        swap(&diaInicial, &diaFinal);
    } else if(anoInicial == anoFinal && mesFinal < mesInicial && diaFinal < diaInicial) {
        swap(&diaInicial, &diaFinal);
    }
    
    int a = anoFinal - 1, b = anoInicial + 1;
    
    qtdAnosBissextos = (a/4 - (b-1)/4) + (a/400 - (b-1)/400) - (a/100 - (b-1)/100);
    qtdAnosNBissextos = (anoFinal - anoInicial - 1) - qtdAnosBissextos;
    
    if(mesInicial <= 2 && checkAnoBissexto(anoInicial)) {
        mes_inicial[1]++;
    }
    if(mesFinal >= 2 && checkAnoBissexto(anoFinal)) {
        mes_final[1]++;
    }
    
    qtdDias += (mes_inicial[mesInicial-1] - diaInicial + 1);
    if(mesInicial < 12) {
        
        //for(aux = mesInicial; aux < 12; aux++) qtdDias += mes_inicial[aux];
    }
    
    qtdDias += diaFinal - 1;
    if(mesFinal > 1) {
        //for(aux = 0; aux < mesFinal - 1; aux++) qtdDias += mes_final[aux];
    }
    
    total += qtdAnosBissextos*366 + qtdAnosNBissextos*365 + qtdDias;
    
    printf("%d\n", total);


    return 0;
}