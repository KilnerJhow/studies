#include <stdio.h>
#include <stdlib.h>

int x;

int main() {
    
    int i, qtdLinha, qtdString;
    
    char** stringDNA;
    
    scanf("%d", &i);
    scanf(" %d %d", &qtdLinha, &qtdString);

    //aloca as colunas em stringDNA
    stringDNA = (char**) malloc((qtdString + 1)*sizeof(char*));
    
    //aloca cada linha em uma coluna do array.
 	for (i = 0; i < qtdString; ++i) {
 	    
 	    //Aloca um valor de memória na posição de stringDNA
 		*(stringDNA+i) = (char*) malloc((qtdLinha)*sizeof(char));
 	}
    
 	//
 	for (i = 0; i < qtdString; ++i) {
 		scanf(" %20s", stringDNA[i]);
 	}

 	for (i = 0; i < qtdString; ++i) {
 		printf("%s\n", stringDNA[i]);
 	}

 	for (i = 0; i < qtdString; ++i) {
 		free( *(stringDNA+i) );
 	}

 	free( stringDNA );

    return 0;
}