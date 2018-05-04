#include <stdio.h>
#include <stdlib.h>

double sum(double a[][2], double x[][10], int k, int i);

int main() {

    int k  = 0, P = 10;
    double a[2][2] = {
        { 2, 1},
        { 5, 7}
    };

    // printf("a[0][0]: %d", )

    //Primeiro elemento linha, segundo coluna
    double b[2]= {11, 13};

    double x[2][P];
    x[0][0] = 1;
    x[1][0] = 1;
    int i = 0, j = 1;

    while(k < P) {

        for(i = 0; i < 2; i++) {
            
            double sum1 = sum(a, x, k, i); 

            x[i][k+1] = ((1/a[i][i]) * (b[i] - sum1));           

        }
        

        k++;

    }

    
    for(i = 0; i < P; i++) {
        printf("X[%d][%d] = %f\n", i%2, i, x[i%2][i]);
    }

    return 0; 
}

double sum(double a[][2], double x[][10], int k, int i) {

    double sum = 0;
    int j;

    for(j = 0; j < 2; j++) {
        if(i != j) {
            sum += a[i][j] * x[j][k];
            printf("Sum: %lf\n", sum);
            printf("X: %lf\n", x[j][k]);
            printf("A: %lf\n", a[i][j]);
        }
    }

    

    return sum;

}
