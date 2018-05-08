#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N_CLIENTE 3 
#define N_SERVIDOR 3
#define N_REQUISICAO 3
#define QTD_PACOTE_ROTEADOR 5
#define QTD_PACOTE_SERVIDOR 10
#define BUFFER_SIZE 10
#define N_ITEMS 200

int buffer_client[BUFFER_SIZE];
int buffer_servidor[N_SERVIDOR][BUFFER_SIZE];

int items = 0; // number of items in the buffer.
int first = 0;
int last = 0; 

pthread_mutex_t mutex_client[N_CLIENTE];
pthread_mutex_t mutex_servidor[N_CLIENTE];

pthread_mutex_t buffer = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t empty[N_SERVIDOR] = PTHREAD_COND_INITIALIZER;
pthread_cond_t fill[N_SERVIDOR] = PTHREAD_COND_INITIALIZER;

typedef struct {
    int pacote_id;
    int serv_dest_id;
} package;

package cliente[N_CLIENTE];

void *servidor();
void *roteador();
void *client();

int main() {





    return 0;
}


void *client(void *id) {

    int tid = *(int *) id;

    for(int i = 0; i < NUM_ITEMS; i++) {
        printf("Cliente#%d produziu %d\n", tid, i);    
    }

}

void put(int i) {
    pthread_mutex_lock(&mutex_client);
    
    pthread_mutex_unlock(&mutex_client);    
}

void *roteador() {


}

void *servidor(void *id) {

    int tid = *(int *) id;

    while(items[tid] == 0) {
        pthread_cond_wait(&fill[tid], &mutex_servidor[tid]);
    }

}