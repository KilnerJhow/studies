#include <stdio.h>

int main() {
    
    double salario, percentual;
    
    printf("Informe o salario do colaborador:\n");
    scanf("%lf", &salario);
    printf("Salario antes do reajuste: %.1lf\n", salario);
    
    if(salario <= 280.00)  percentual = 0.2;
    
    else if(salario > 280.00 && salario <= 700) percentual = 0.15;
    
    else if(salario > 700 && salario <= 1500) percentual = 0.1;
    
    else percentual = 0.05;
        
    
    
    
    printf("Percentual de aumento aplicado: %.0lf%%\n",percentual*100);
    percentual *= salario;
    printf("Valor do aumento: %.14lf\n", percentual);
    printf("Salario com reajuste: %.2lf\n", salario+percentual);
    
    return 0;
}