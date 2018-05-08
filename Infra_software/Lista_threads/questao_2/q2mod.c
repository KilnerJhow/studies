#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *jacobi_algorithm(void *(N));
double sum(int k, int i);

#define N_ITERACOES 10
#define N_ICOGNITA 3

//Matriz dos constantes que multiplicam x e y
double a[3][3] = {
    { 1, -1, 1},
    { 1, 1, -1},
    { 1, 1,  3}
};

//Primeiro elemento linha, segundo coluna
//Valores do segundo membro de cada equação
double b[2] = {4, 2, 3};

//Icógnitas do tipo X[i]^k, limitadas pelo n° de iterações
//Possui 2 variáveis e 10 iterações
double x[3][N_ITERACOES];

static pthread_barrier_t barrier;
static pthread_mutex_t print = PTHREAD_MUTEX_INITIALIZER;

int main() {
        
    x[0][0] = 1;
    x[1][0] = 1;
    x[2][0] = 1;

    //Var auxiliar
    int i = 0, j = 0, N = 2, N_Icognitas = 2;

    int pass_thread = N_Icognitas/N;

    pthread_t thread[N];
    int tid[N];

    pthread_barrier_init(&barrier, NULL, N);

    for(i = 0; i < N; i++) {
        tid[i] = i;
        pthread_create(&thread[i], NULL, jacobi_algorithm, (void*) &tid[i]);
    }
    
    for(i = 0; i < N; i++) {
        pthread_join(thread[i], NULL);
    }

    for(i = 0; i < N_ITERACOES; i++) {
        
        if(i%2 == 0) {
            j++;
            printf("\n");
        }
        
        printf("X[%d]^(%d) = %f\n", i%2, j, x[i%2][i]);
        
    }

    exit(0);
}

void *jacobi_algorithm(void *(N)) {
    
    int k = 0, P = N_ITERACOES, i;
    int tid = *(int*) N;

    printf("Thread: %d\n", tid);
    while(k < P) {

        //Se existirem apenas 2 threads e 4 icognitas
        //cada thread cuida de 2 icognitas
        for(i = 0; i < N_ICOGNITA; i++) {
            
            double sum1 = sum(k, i); 
            pthread_mutex_lock(&print);
            printf("Thread#%d calculando x[%d][%d]\n", tid, tid, k + 1);
            pthread_mutex_unlock(&print);
            
            x[tid][k + 1] = ((1/a[i][i]) * (b[i] - sum1));             
        }
        
        //Sincroniza cada thread para passar para a próxima iteração
        pthread_barrier_wait(&barrier);
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