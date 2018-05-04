#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define N_AEROTAXI 10
#define N_ESTACOES 5
#define N_AEROTAXI_SIMULTANEO 2
#define N_ITERACOES 5 //Apenas para ver o programa funcionando, caso contrário seria um loop infinito e a saída seria conturbada

int station[N_ESTACOES];
int count_station[N_ESTACOES];
int signal_count[N_ESTACOES];
int arrive_left_station[N_AEROTAXI];


//Mutex de cada estação onde um aerotaxi pousa por vez, mas permite 2 aerotaxis simultaneos
static pthread_mutex_t mutex_station[N_ESTACOES];

//Mutex utilizado junto com a condição para sinalizar que o aerotaxi pode pousar na estação
static pthread_mutex_t cond_mutex_station[N_ESTACOES];

//Condição utilizada para sinalizar para um aerotaxi que ele pode pousar na estação
static pthread_cond_t cond_station[N_ESTACOES];

//Mutex utilizado para printar corretamente a chegada e a saída dos aerotaxis das estações
static pthread_mutex_t print_1 = PTHREAD_MUTEX_INITIALIZER;


//O aerotaxi deve pousar na estação e aguardar 500 milissegundos para embarque
//Apenas 2 aerotáxis por estação
//Se houver um terceiro aguardando pouso, deve esperar e ser informado quando houver uma vaga
void* taxi_(void *id) {

    //A estação atual do taxi
    int taxi_id = *(int *)id;
    
    //O aerotaxi começa em uma estação aletória
    int current_station = rand()%N_ESTACOES;
    
    int ct = 0;

    while(ct < N_ITERACOES) {

        
        pthread_mutex_lock(&cond_mutex_station[current_station]);

        //Pousam na estação requerida
        if(count_station[current_station] >= N_AEROTAXI_SIMULTANEO) {

            //Se houver já 2 táxis pousados, o 3° aguarda a liberação de um dos dois
            printf("Taxi#%d esperando pouso na estacao#%d!\n", taxi_id, current_station + 1);

            //Enquanto a variável da estação for igual ao número de aerotaxi simultaneos, espera pela condição
            // while(count_station[current_station] == N_AEROTAXI_SIMULTANEO)
            pthread_cond_wait(&cond_station[current_station], &cond_mutex_station[current_station]);
        }

        pthread_mutex_unlock(&cond_mutex_station[current_station]);

        pthread_mutex_lock(&mutex_station[current_station]);    
        //Incrementamos o valor do contador da estação
        count_station[current_station]++;

        //Usado para contar se o táxi quando chega na estação, ele realmente sai ou se pula pra outra estação
        arrive_left_station[taxi_id]++;


        // Desbloqueamos o mutex para que outro aerotaxi possa pousar
        pthread_mutex_unlock(&mutex_station[current_station]);

        //Aguardamos 500 milissegundos para o embarque
        usleep(5000);

        //Bloqueamos novamente o mutex para poder decrementar a quantidade de taxis pousados
        pthread_mutex_lock(&mutex_station[current_station]);
        pthread_mutex_lock(&print_1);
        printf("Taxi#%d embarcando passageiros na estacao#%d! - %d\n", taxi_id, current_station + 1, taxi_id);

        //Termniou o embarque e vai embora
        count_station[current_station]--;

        arrive_left_station[taxi_id]--;

        printf("Taxi#%d saindo da estacao#%d! - %d\n", taxi_id, current_station + 1, arrive_left_station[taxi_id]);

        pthread_mutex_unlock(&print_1);
        pthread_mutex_unlock(&mutex_station[current_station]);

        //Taxi decolou, avisa a qualquer um que estiver esperando que ele pode pousar
        pthread_cond_signal(&cond_station[current_station]);


        //O táxi atual vai para a próxima estação
        current_station = (current_station + 1)%N_ESTACOES;
        ct ++;
    }
    pthread_exit(NULL);
}

int main() {

    //Os aerotaxis
    pthread_t aerotaxi[N_AEROTAXI];
    int tid[N_AEROTAXI];

    srand((unsigned) time(NULL));

    for(int i = 0; i < N_ESTACOES; i++) {
        pthread_mutex_init(&mutex_station[i], NULL);
        pthread_cond_init(&cond_station[i], NULL);
        pthread_mutex_init(&cond_mutex_station[i], NULL);

        signal_count[i] = 0;
        count_station[i] = 0;
        station[i] = i;
        arrive_left_station[i] = 0;
    }

    for(int i = 0; i < N_AEROTAXI; i++) {
        tid[i] = i;
        pthread_create(&aerotaxi[i], NULL, taxi_, (void*) &tid[i]);
    }    

    for(int i = 0; i < N_AEROTAXI; i++) {
    
        pthread_join(aerotaxi[i], NULL);
    }

    exit(0);
}