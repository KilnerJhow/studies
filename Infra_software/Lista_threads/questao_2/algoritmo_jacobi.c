#include <stdio.h>
#include <stdlib.h>

double sum(double a[][3], double x[][10], int k, int i);

int main() {

    int k  = 0, P = 10;
   
    double a[3][3] = {
        { 1, -1, 1},
        { 1, 1, -1},
        { 1, 1,  3}
    };

    // printf("a[0][0]: %d", )

    //Primeiro elemento linha, segundo coluna

    double b[3] = {4, 2, 3};

    double x[3][P];
    x[0][0] = 1;
    x[1][0] = 1;
    x[2][0] = 1;
    int i = 0, j = 1;

    while(k < P) {

        for(i = 0; i < 3; i++) {
            
            double sum1 = sum(a, x, k, i); 

            x[i][k+1] = ((1/a[i][i]) * (b[i] - sum1));           

        }
        

        k++;

    }

    
    for(i = 0; i < 3; i++) {
        for(j = 0; j < P; j++) {
            printf("X[%d][%d] = %.2f\n", i, j, x[i][j]);
        }
        
    }

    printf("Valores finais: %lf %lf %lf\n", x[0][9], x[1][9], x[2][9]);

    return 0; 
}

double sum(double a[][3], double x[][10], int k, int i) {

    double sum = 0;
    int j;

    for(j = 0; j < 3; j++) {
        if(i != j) {
            sum += a[i][j] * x[j][k];
            printf("Sum: %lf\n", sum);
            printf("X: %lf\n", x[j][k]);
            printf("A: %lf\n", a[i][j]);
        }
    }

    

    return sum;

}
