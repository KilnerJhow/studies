#include <stdio.h>


int main() {
    
    int x;
    scanf("%d", &x);
    if(x < 16) printf("nao eleitor");
    else if(x >= 18 && x <= 65) printf("eleitor obrigatorio");
    else printf("eleitor facultativo");
    
    return 0;
}