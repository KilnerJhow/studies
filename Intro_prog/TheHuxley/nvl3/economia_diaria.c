#include <stdio.h>

int main() {
    
    int i, count = 0;
    float valor[7], sum = 0;
    scanf("%f", &valor[0]);
    sum = valor[0];
    
    for(i = 1; i < 7; i++) {
        
        scanf("%f", &valor[i]);
        if((valor[i]-valor[i-1]) >= 0.5) {
            count++;
        }
        sum += valor[i];
    }
    
    printf("R$ %.2f\n", sum);
    printf("%d\n", count);
    return 0;
}