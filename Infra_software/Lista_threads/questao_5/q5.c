#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N_PESSOA 20
#define N_FILA 3
#define CAP_AEROTAXI 4
#define TIME_EMBARQUE 2000
#define TIME_PROX 5000
#define VAZIA 0

int fila_t[N_FILA];
int cap_atual_aerotaxi = 0, vazia = 0;

pthread_mutex_t mutex_fila[N_FILA];
pthread_mutex_t mutex_fila1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t print = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_control = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_embarque[N_FILA];
pthread_cond_t cond_fila_response[N_FILA];

void *fila(void *id) {

    int fila_id = *(int *) id;
    
    while(1) {
        if(fila_t[fila_id] > 0) {
            pthread_mutex_lock(&mutex_fila1);

            pthread_cond_wait(&cond_embarque[fila_id], &mutex_fila1);

            pthread_mutex_lock(&print);
            //Uma pessoa da fila embarcou
            fila_t[fila_id]--;
            cap_atual_aerotaxi--;
            printf("Passageiro da fila#%d entrando no aerotaxi\n", fila_id);
            printf("Passageiros restantes na fila#%d - %d\n", fila_id, fila_t[fila_id]);

            usleep(TIME_EMBARQUE);

            pthread_mutex_unlock(&print);

            pthread_cond_signal(&cond_fila_response[fila_id]);
            
            pthread_mutex_unlock(&mutex_fila1);

        } else {
            // printf("Fila vazia, saindo da thread#%d\n", fila_id);
            vazia++;
            break;
        }
    }
    pthread_exit(NULL);

}

void *control(void *id) {

    int control_id = *(int *) id;
    int ct = 0, i = 0;

    while(1) {
        
        //O aerotáxi tanto pode estar cheio ou vazio
        //Essa variável decide quantos lugares livres o aerotaxi tem
        //Porém como é uma variável compartilhada com as outras threads, ela só pode ser mudada
        //se nenhuma outra thread a estiver utilizando
        pthread_mutex_lock(&mutex_fila1);
        cap_atual_aerotaxi = rand()%(CAP_AEROTAXI + 1);
        pthread_mutex_unlock(&mutex_fila1);
        
        // printf("\nCap atual do aerotaxi: %d\n", cap_atual_aerotaxi);

        while(cap_atual_aerotaxi > 0 && vazia < N_FILA) {

            if(fila_t[i] > 0) {
                //Avisamos a thread que ela pode embarcar 1 passageiro
                pthread_cond_signal(&cond_embarque[i]);
            }
            //A sequência de escolha dos passageiros para o aerotáxi é sequencial
            i = (++i) % N_FILA;
        }   

        // printf("Lotacao do aerotaxi: %d\n", cap_atual_aerotaxi);
        //Esperamos o tempo de chegada do próximo aerotaxi
        usleep(TIME_PROX);
                
        if(vazia == N_FILA) {
            printf("Todas as filas esvaziadas\n");
            break;
        }
        ct++;        

    }
    pthread_exit(NULL);
}

int main() {

    pthread_t tid_fila[N_FILA];
    pthread_t tid_control;
    int id_fila[N_FILA], id_control = 0;

    for(int i = 0; i < N_PESSOA; i++) {
        //Inicializamos cada fila com o máximo de pessoas
        fila_t[i] = N_PESSOA;
    }

    for(int i = 0; i < N_FILA; i++) {
        pthread_cond_init(&cond_embarque[i], NULL);
        pthread_cond_init(&cond_fila_response[i], NULL);
        pthread_mutex_init(&mutex_fila[i], NULL);
    }
    
    

    for(int i = 0; i < N_FILA; i++) {
        id_fila[i] = i;
        pthread_create(&tid_fila[i], NULL, fila, (void*) &id_fila[i]);
    }

    pthread_create(&tid_control, NULL, control, (void*) &id_control);

    pthread_join(tid_control, NULL);

    for(int i = 0; i< N_FILA; i++) {
        printf("Fila %d: %d\n",i, fila_t[i]);
    }

    exit(0);
}