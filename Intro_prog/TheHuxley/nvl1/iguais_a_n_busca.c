#include <stdio.h>

int main() {
    
    int vet[101], i;
    
    for(i = 0; i < 101; i++) {
        scanf("%d", &vet[i]);
    }
    for(i = 0; i < 100; i++) {
        if(vet[100] == vet[i]) printf("%d\n", i);
    }
}