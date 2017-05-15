#include <stdio.h>

int main() {
    
    int i, somaFinal = 0, mesFinal, diaFinal;
    int mes_final[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    scanf("%d/%d", &diaFinal, &mesFinal);
    
    for(i = 0; i < mesFinal - 1; i++) {
        somaFinal += mes_final[i];
    }
    somaFinal += diaFinal - 1;
    
    printf("%d\n", somaFinal);
    
    return 0;
}