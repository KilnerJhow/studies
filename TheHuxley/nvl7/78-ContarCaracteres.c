#include <stdio.h>
#include <string.h>

int parLetra(char frase[]) {
    
    
}

int espacoBranco(char frase[]) {
    int i = 0, espBranco = 0;
    for(i = 0; frase[i] != '\0'; i++){
        if(frase[i] == ' ') espBranco++;
    }
    return espBranco;
}

int contaA(char frase[]) {
    int i = 0, countA = 0;
    while(frase[i] != '\0'){
        if(frase[i] == 'a' || frase[i] == 'A') countA++;
        i++;
    }
    return countA;
}



int main() {
    
    char fraseFinal[] = "NAO QUERO MAIS";
    char frase[80];
    scanf("%79[^\n]s", frase);
    __fpurge(stdin);
    do{
        printf("%d\n", espacoBranco(frase));
        printf("%d\n", contaA(frase));
        scanf("%79[^\n]s", frase);
        __fpurge(stdin);
        //fflush(stdin);
    } while(strcmp(frase,fraseFinal) != 0);
    return 0;
}