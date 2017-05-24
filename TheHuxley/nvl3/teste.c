#include <stdio.h>
#include <stdlib.h>

void swap(long double** a, int l1, int l2) {
	long double* t = a[l1];
	a[l1] = a[l2];
	a[l2] = t;
}

int main(int argc, char const *argv[]) {
	
	int size, i, j, k, ct = 0;
	long double** a;
	long double* x;
	long double mul, s;
	

	while(scanf(" %d", &size) != EOF) {

		//aloca o array solução.
		x = (long double*) malloc(sizeof(long double)*size);
		
		//aloca o array
	    a = (long double**) malloc(sizeof(long double*)*size);
	    for (i = 0; i < size; ++i) {
	    	a[i] = (long double*) malloc(sizeof(long double)*(size+1));
	    	//recebe as entradas
	    	for (j = 0; j <= size; ++j) {
	    		scanf(" %Lf", &a[i][j]);
	    	}
	    }
	    
	    //resolve o sistema.
	    //itera sobre cada coluna do sistema.
	    for (j = 0; j < size; ++j) {
	    	//verifica se o elemento diagonal da linha é zero.
	    	if(a[j][j] == 0) {
	    		//realiza uma busca por uma linha que não tenha o elemento zero e troca.
	    		for (i = 0; i < size; ++i) {
	    			//troca as duas linhas
	    			if(a[i][j] != 0) {
	    				swap(a, i, j);
	    				break;
	    			}
	    		}
	    	}

	    	//divide a linha pelo valor da diagonal.
	    	mul = 1.0/a[j][j];
	    	for (i = 0; i <= size; ++i) {
	    		a[j][i] *= mul;
	    	}

	    	//subtrai as linhas abaixo para zerar aquele elemento.
			//itera nas linhas
	    	for (i = j + 1; i < size; ++i) {
	    		mul = a[i][j];
	    		//itera nas colunas
	    		for (k = j; k <= size; ++k) {
	    			a[i][k] -= a[j][k]*mul;
	    		}
	    	}
	    }

	    //acha cada valor de saída.
		x[size-1] = a[size-1][size];
		for (k = (size-2); k >= 0; k--){
			s = 0;
			//itera no array realizando sucessivas subtrações dos coeficientes.
			for (j = k + 1;j < size; j++) {
			   s = s + ( a[k][j]*x[j] );
			}

			x[k]=(a[k][size] - s);
		}

		if(ct > 0) printf("\n");
	    printf("Case #%d: ", ++ct);
	    for (i = 0; i < size - 1; ++i) {
	    	printf("%.2Lf ", x[i]);
	    }
	    printf("%.2Lf", x[i]);

	    //libera a memória
	    for (i = 0; i < size; ++i) free(a[i]);
	    free(a);

	}

	return 0;
}