#include <stdio.h>

int coluna;

void calculaDeterminante(int array[][coluna], int coluna, int linha) {
    
    int i, j, maiorZero = 0, menorZero = 0, diagonalPrincipal = 0, diagonalSecundaria = 0, linhaAux = 0, colunaAux = coluna-1;
    printf("Matriz formada:\n");
    
    for(;colunaAux >= 0; colunaAux--, linhaAux++){
        diagonalSecundaria += array[linhaAux][colunaAux];
    }
    for(j = 0; j < linha; j++) {
        for(i = 0; i < coluna; i++){
            printf("%d", array[j][i]);
            if(i != coluna-1) printf(" ");
            if(i == j) diagonalPrincipal += array[j][i];
            if(array[j][i] > 0) maiorZero++;
            else menorZero++;
        }
        printf("\n");
    }
    if(coluna == linha) printf("A diagonal principal e secundaria tem valor(es) %d e %d respectivamente.\n", diagonalPrincipal, diagonalSecundaria);
    else printf("A diagonal principal e secundaria nao pode ser obtida.\n");
    printf("A matriz possui %d numero(s) menor(es) que zero.\n", menorZero);
    printf("A matriz possui %d numero(s) maior(es) que zero.\n", maiorZero);
}

int main() {
    
    int linha, i = 0, j;
    scanf("%d%d", &linha, &coluna);
    int array[linha][coluna];
    
    for(j = 0; j < linha; j++) {
        for(i = 0; i < coluna; i++){
            scanf("%d", &array[j][i]);
        } 
    }
    calculaDeterminante(array, coluna, linha);
    
    
    return 0;
}