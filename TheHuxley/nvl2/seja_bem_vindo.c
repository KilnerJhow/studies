#include <stdio.h>


int main() {
    
    char nome[120];
    scanf("%119[^\n]s", nome);
    
    printf("Seja muito bem-vindo %s", nome);
    
    return 0;
}