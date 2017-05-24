#include <stdio.h>
#include <stdlib.h>

void swap(double** arr, int i, int j) {

	double* tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;

}

void printarray(double** arr, int size) {

	int i, j;
	for(i = 0; i < size; i++) {
		for(j = 0; j <= size; j++) printf("%.2lf ", arr[i][j]);
		printf("\n");
	}

}

int main() {
    
    double** arr;
    double* resposta;
    int size, i, j;
    
    scanf("%d", &size);
    //Pega o tamanho da linha
    // while(scanf("%d", &size) != EOF) {

    	//A quantidade de respostas é igual a quantidade de linhas
    	resposta = (double*) malloc(size*sizeof(double));

    	//Aloca uma quantidade n de linhas
    	arr = (double**) malloc(size*sizeof(double*));

    	//Aloca uma quantidade n+1 de colunas devido as respostas na última coluna
    	for (i = 0; i < size; ++i) {
    		arr[i] = (double*) malloc((size+1)*sizeof(double));
    		
    		for (j = 0; j <= size; ++j) {
        		// Podemos fazer isso pois já alocamos a primeira linha da matriz
        		scanf(" %lf", &arr[i][j]);
		    }    
    		
    	}

        printarray(arr, size);
        
        printf("\n");
    	for (i = 0, j = 0; i < size; ++i) {
            if(arr[i][i] == 0) {
                while(arr[j][i] == 0 && j < size) j++;
                swap(arr, i, j);
            }
    	}

        printarray(arr, size);




        free(resposta);
        for (i = 0; i < size; i++) {
            free(arr[i]);
        }
        free(arr);
    // }
    

    return 0;
}