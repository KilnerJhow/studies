#include <stdio.h>

int main() {
    
    double salario;
    
    scanf("%lf", &salario);
    if(salario < 1000) salario = salario*0.3 + salario;
    else if(salario > 2000) salario = salario;
    else salario = 0.1*salario + salario;
    
    printf("%.2lf\n", salario);
    
    return 0;
}