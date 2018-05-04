#include <stdio.h>

int main() {
    
    double a, b, c, media;
    scanf("%lf%lf%lf", &a, &b, &c);
    
    media = (a+b+c)/3;
    
    if(media >= 7) printf("aprovado\n");
    else if(media < 3) printf("reprovado\n");
    else printf("prova final\n");
    
    
    return 0;
}