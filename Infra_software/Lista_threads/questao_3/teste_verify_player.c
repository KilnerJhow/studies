#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define IDLE 0
#define PAPER 1
#define SCISSOR 2
#define ROCK 3
#define LOSE 4
#define WIN 5

#define MAX_PLAYERS 5

int player[MAX_PLAYERS];
int T = MAX_PLAYERS;
int winner = MAX_PLAYERS;
int losers[MAX_PLAYERS];

void get_player_played(int i) {
     player[i] = 1 + rand()%3;
}

void verifyPlayers() {

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

}

int main() {
    
    int i = 0;

    srand( (unsigned)time(NULL) );

    for(i = 0; i < MAX_PLAYERS; i++) {
        get_player_played(i);

        printf("Player#%d: ", i);
        switch(player[i]) {
            case ROCK:
                printf("rock\n");
                break;
            case SCISSOR:
                printf("scissor\n");
                break;
            case PAPER:
                printf("paper\n");
                break;
            default:
                printf("error");
                break;
        }

    }

    

    verifyPlayers();

    // printf("Winner: %d\n", winner);
    int ct = 0;
    if(winner > 1) {
        while(winner >= 2) {

            for(i = 0; i < MAX_PLAYERS; i++) {
                if(player[i] != LOSE) {
                    get_player_played(i);
                    // printf("Player#%d: %d\n", i, player[i]);
                }
            }

            verifyPlayers();
            // printf("Winner: %d\n", winner);
            ct ++;

        }
    }
    // printf("CT: %d\n", ct);

    for(i = 0; i < MAX_PLAYERS; i++) {
        if(player[i] != LOSE && winner == 1) {
            player[i] = WIN;
        }
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
            default:
                printf("Draw!\n");
        }
    }

}