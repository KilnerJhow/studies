#include <stdio.h>

int quantidadeDeCaracters(const char *str, const char caracter) {
    
    int i = 0, count;
    for(; str[i] != '\0'; i++) {
        if(str[i] == caracter) count++; 
    }
    
    return count;
}


int main() {
    
    char str[50], caractere;
    
    scanf("%49s", str);
    scanf(" %c", &caractere);
    
    printf("%d\n", quantidadeDeCaracters(str, caractere));
    
    return 0;
}