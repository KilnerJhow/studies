#include <stdio.h>
#include <stdlib.h>

int main() {
        
    typedef struct {
        int idade;
        char nome[1000];
        char sexo;
        char estadoCivil;
        int qtdFotos;
        int qtdAmigos;
    } Usuarios;
    
    int qtdUsuarios, i;
    
    scanf(" %d", &qtdUsuarios);
    Usuarios usuario[qtdUsuarios];

    for(i = 0; i < qtdUsuarios; i++) {

        scanf(" %d", &usuario[i].idade);
        
        scanf(" %48s", usuario[i].nome);
        scanf(" %c", &usuario[i].sexo);
        scanf(" %c", &usuario[i].estadoCivil);
        scanf(" %d", &usuario[i].qtdFotos);
        scanf(" %d", &usuario[i].qtdAmigos);
        
        printf("\nIdade: %d\n", usuario[i].idade);
        printf("Nome: %s\n", usuario[i].nome);
        printf("Sexo: %c\n", usuario[i].sexo);
        printf("Estado Civil: %c\n", usuario[i].estadoCivil);
        printf("Numero de amigos: %d\n", usuario[i].qtdFotos);
        printf("Numero de fotos: %d\n", usuario[i].qtdAmigos);

    }
    printf("\n");
    
    
    return 0;
}