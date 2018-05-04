#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *jacobi_algorithm(void *(N));
double sum(int k, int i);

//Matriz dos constantes que multiplicam x e y
double a[2][2] = {
    { 2, 1},
    { 5, 7}
};

//Primeiro elemento linha, segundo coluna
//Valores do segundo membro de cada equação
double b[2] = {11, 13};

//Icógnitas do tipo X[i]^k, limitadas pelo n° de iterações
//Possui 2 variáveis e 10 iterações
double x[2][10];

static pthread_barrier_t barrier;

int main() {
        
    x[0][0] = 1;
    x[1][0] = 1;

    //Var auxiliar
    int i = 0, j = 1, N = 2, N_Icognitas = 2;

    int pass_thread = N_Icognitas/N;

    pthread_t thread[N];

    pthread_barrier_init(&barrier, NULL, N);

    for(i = 0; i < N; i++) {
        pthread_create(&thread[i], NULL, jacobi_algorithm, (void*) &pass_thread);
    }
    
    for(i = 0; i < N; i++) {
        pthread_join(thread[i], NULL);
    }

    for(i = 0; i < 10; i++) {
        printf("X[%d][%d] = %f\n", i%2, i, x[i%2][i]);
    }

    exit(0);
}

void *jacobi_algorithm(void *(N)) {
    
    int k = 0, P = 10;
    int i;
    int *ct = (int*) N;
    printf("Thread: %d\n", *ct);
    while(k < P) {

        for(i = 0; i < 2; i = i + *ct) {
            
            double sum1 = sum(k, i); 

            x[i][k + 1] = ((1/a[i][i]) * (b[i] - sum1));         

            pthread_barrier_wait(&barrier);
        }
        

        k++;

    }
    pthread_exit(NULL);
}

double sum(int k, int i) {

    double sum = 0;
    int j;

    for(j = 0; j < 2; j++) {
        if(i != j) {
            sum += a[i][j] * x[j][k];
            // printf("Sum: %lf\n", sum);
            // printf("X: %lf\n", x[j][k]);
            // printf("A: %lf\n", a[i][j]);
        }
    }
    return sum;

}