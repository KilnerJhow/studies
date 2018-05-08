#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define IDLE 0
#define PAPER 1
#define SCISSOR 2
#define ROCK 3
#define LOSE 4
#define WIN 5

void *game();
void verifyPlayers();
void get_player_played();

pthread_barrier_t barrier;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_draw = PTHREAD_MUTEX_INITIALIZER;

int *player;
int T = 3, winner;

int main() {

    int i, err;

    // scanf(" %d", &T);

    srand( (unsigned)time(NULL) );

    pthread_t thread[T];

    err = pthread_barrier_init(&barrier, NULL, T);

    player = (int*) malloc(T * sizeof(int));
    
    //Todos são vencendores
    winner = T;

    for(i = 0; i < T; i++) {
        player[i] = IDLE;
    }

    if(err != 0) {
        printf("Erro criacao da barrier!\n");
        exit(-1);
    }

    for(i = 0; i < T; i++) {
        // printf("Creating thread#%d\n\n", i);
        err = pthread_create(&thread[i], NULL, game, (void *) &i);
        if(err != 0) {
            printf("Erro criacao thread!\n");
            exit(-1);
        }
    }

    for(i = 0; i < T; i++) {
        pthread_join(thread[i], NULL);
    }

    for(i = 0; i < T; i++) {
        if(winner == 1 && player[i] != LOSE) player[i] = WIN;
    }

    for(i = 0; i < T; i++) {
        printf("Player %d: %d ", i, player[i]);
        switch(player[i]) {
            case WIN:
                printf("Win!\n");
                break;
            case LOSE:
                printf("Lose!\n");
                break;
        }
    }

    exit(0);
}

void *game(void *i) {

    int x = *(int*) i;
    
    printf("Thread#%d Waiting\n\n", x);
    pthread_barrier_wait(&barrier);

    int n, ret;

    int ct = 0;

    while(player[x] != LOSE && winner >= 2) {

        n = 1 + (rand() % 3);
        player[x] = n;
        printf("Thread#%d - Player: %d\n", x, player[x]);
        pthread_barrier_wait(&barrier);


        verifyPlayers();
    }

    if(player[x] == LOSE) {
        printf("Thread#%d leaving\n", x);
    }

    printf("Thread#%d - CT: %d\n", x, ct);
    printf("Winner: %d\n", winner);


    pthread_exit(NULL);
}

void verifyPlayers() {

    pthread_mutex_lock(&mutex);
    // printf("Locked!\n");
    int i, j;

    for(i = 0; i < T; i++) {
        if(player[i] != LOSE) {
            
            for(j = i + 1; j < T; j++) {
                if(player[j] != LOSE) {
                    if(player[i] == ROCK && player[j] == PAPER) {
                        player[i] = LOSE;
                        winner--;
                        break;
                    }

                    if(player[i] == ROCK && player[j] == SCISSOR) {
                        player[j] = LOSE;
                        winner--;
                        break;
                    }

                    if(player[i] == SCISSOR && player[j] == PAPER) {
                        player[j] = LOSE;
                        winner--;
                    }

                    if(player[i] == PAPER && player[j] == SCISSOR) {
                        player[i] = LOSE;
                        winner--;
                        break;
                    }

                    if(player[i] == PAPER && player[j] == ROCK) {
                        player[j] = LOSE;
                        winner--;
                    }

                    if(player[i] == SCISSOR && player[j] == ROCK) {
                        player[i] = LOSE;
                        winner--;
                        break;
                    }

                }

                // printf("Player#%d: %d and Player#%d: %d\n", i, player[i], j, player[j]);
                // if(player[i] != LOSE && player[j] != LOSE) {
                //     printf("Player#%d and Player #%d draw!\n\n", i, j);
                // } 

                // if(player[i] != LOSE && player[j] == LOSE) {
                //     printf("Player#%d Win and Player #%d lose!\n\n", i, j);
                // }

                // if(player[i] == LOSE && player[j] != LOSE) {
                //     printf("Player#%d lose and Player #%d Win!\n\n", i, j);
                // }

            }

        }
    }
    pthread_mutex_unlock(&mutex);
    // printf("Unlocked!\n");
}

//
void get_player_played(int i) {
     player[i] = 1 + rand()%3;
}