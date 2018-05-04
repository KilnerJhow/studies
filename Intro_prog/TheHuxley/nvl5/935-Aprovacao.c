#include <stdio.h>

int main() {
    
    long double nota, sum = 0;
    int x = 0;
    printf("Informe a primeira nota:\n");
    scanf("%Lf", &nota);
    sum += nota;
    
    printf("Informe a segunda nota:\n");
    scanf("%Lf", &nota);
    sum += nota;
    
    printf("Informe a terceira nota:\n");
    scanf("%Lf", &nota);
    sum += nota;
    
    sum = sum/3.0;
    
    if(sum < 5.0) printf("Reprovado com media %.1Lf\n", sum);
    else if(sum >= 7.0) printf("Aprovado com media %.1Lf\n", sum);
    else printf("Recuperacao com media %.15Lf\n", sum);
    
    return 0;
}