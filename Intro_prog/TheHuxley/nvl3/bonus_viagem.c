#include <stdio.h>

int main() {
    
    double salario, bonus;
    scanf("%lf", &salario);
    bonus = 0.75*salario;
    if(bonus < 2000 ) {
        printf("ARGENTINA");
    } else if(bonus >= 2000 && bonus <= 3000) {
        printf("ESPANHA");
    } else {
        printf("ALEMANHA");
    }
    return 0;
}