#include <stdio.h>


int main() {
    
    int n, a, b, aux = 0;
    
    scanf("%d", &n);
    scanf("%d", &a);
    scanf("%d", &b);
    aux = a;
    while(1) {
        if(aux % n == 0){
            printf("%d\n", aux);
        }
        if(aux >= b) {
            if(n > b) printf("INEXISTENTE");
            break;
        }
        aux ++;
    }
    
    return 0;
}