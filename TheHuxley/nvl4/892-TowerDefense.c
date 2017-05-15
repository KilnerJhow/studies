#include <stdio.h>
#include <stdlib.h>

#define ACCESSED -1

typedef struct{
    
    int x;
    int y;
    
} parOrdenado;


void ataqueInimigos(char** mapa, int coluna, int linha) {
    
    int i, j, nInimigos = 0, nTorres = 0;

    int qtdTorres = 0, qtdInimigos = 0;
    
    parOrdenado inimigos[100];
    parOrdenado torres[100];
    
    for(i = 0; i < linha; i++) {
           
            for(j = 0; j < coluna; j++) {
                
                //printf("I: %d J: %d\n", i, j);
                //printf("I: %d J: %d Mapa: %c\n",i, j, mapa[i][j]);
                if(mapa[i][j] == '.') continue;
                
                else if(mapa[i][j] == '*') {
                    inimigos[qtdInimigos].x = i;
                    inimigos[qtdInimigos].y = j;
                    qtdInimigos++;
                }
                
                else if(mapa[i][j] == '&') {
                    torres[qtdTorres].x = i;
                    torres[qtdTorres].y = j;
                    qtdTorres++;
                }
                
                
            }
    }
    
    //printf("Inimigos: %d Torres: %d\n", qtdInimigos, qtdTorres);
    
    int isXok = 0, isYok = 0, aux2 = 0, aux3 = 0, xTorre, yTorre, xInimigo, yInimigo;
    
    for(i = 0; i < qtdTorres; i++) {
        
        //printf("Torre: X = %d, Y = %d\n", torres[i].x, torres[i].y);
        
        for(j = 0; j < qtdInimigos; j++) {
        
            xTorre = torres[i].x;
            yTorre = torres[i].y;
            
            xInimigo = inimigos[j].x;
            yInimigo = inimigos[j].y;
            
            //printf("Inimigo: X = %d, Y = %d\n", inimigos[j].x, inimigos[j].y);
            
            
            if((xTorre - 2) == xInimigo || (yTorre - 2) == yInimigo || (xTorre + 2) == xInimigo || (yTorre + 2) == yInimigo) continue;
            
            if(yInimigo == ACCESSED || xInimigo == ACCESSED) continue;
            
            if(xTorre >= xInimigo) {
                
                if(xTorre == xInimigo){
                    isXok++;
                    inimigos[j].x = ACCESSED;
                } 
                else {
                    xTorre--;
                    if(xTorre == xInimigo) {
                        isXok++;
                        inimigos[j].x = ACCESSED;
                    }
                    else isXok--;
                }
            } else if(xTorre < xInimigo) {
                
                xTorre++;
                if(xTorre == xInimigo){
                    isXok++;
                    inimigos[j].x = ACCESSED;
                } 
                else isXok--;
                
            }
            
            if(yTorre >= yInimigo) {
                
                if(yTorre == yInimigo){
                    isYok++;
                    inimigos[j].y = ACCESSED;
                } 
                else {
                    yTorre--;
                    if(yTorre == yInimigo) {
                        isYok++;
                        inimigos[j].y = ACCESSED;
                     }
                    else isYok--;
                }
            } else if(yTorre < yInimigo) {
                
                yTorre++;
                if(yTorre == yInimigo){
                    isYok++;
                    inimigos[j].y = ACCESSED;
                } 
                else isYok--;
            }
            
            
            //printf("X: %d, Y: %d\n", isXok, isYok);
        }
        
        
    }
    
    if((isXok == qtdInimigos && isYok == qtdInimigos) || (isXok == qtdTorres) && (isYok == qtdTorres)) printf("S\n");
    else printf("N\n");
    
}


void swap(int* a, int* b){
    
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    
}

int main() {
        
    char** string = NULL;
    
    int linha, coluna, i, aux = 0, aux1;
    
    scanf("%d %d", &linha, &coluna);
    
    //printf("Linha: %d, Coluna: %d\n", linha, coluna);
    
    if(linha > coluna) aux = 1;
    
    if(!aux) string = (char**) malloc((coluna + 1)*sizeof(char*));
    else string = (char**) malloc((linha + 1)*sizeof(char*));
    
    if(!aux) aux1 = coluna;
    else aux1 = linha;
    
    for(i = 0; i < aux1; i++) {
        if(!aux) *(string + i) = (char*) malloc((linha)*sizeof(char));
        else *(string + i) = (char*) malloc((coluna)*sizeof(char));
    }
    
    /*
    if(linha > coluna) swap(&linha, &coluna);
    
    string = (char**) malloc((coluna + 1)*sizeof(char*));

    
    
    for(i = 0; i < coluna; i++) {
        *(string + i) = (char*) malloc((linha)*sizeof(char));
    }*/
    
    for(i = 0; i < linha; i++) {
        //printf("%2d", i);
        scanf(" %s", string[i]);
        //printf(" %s\n", string[i]);
    }
    //printf("\n");
    
    //printMapa(string, coluna, linha);
    
    ataqueInimigos(string, coluna, linha);
    
    for (i = 0; i < coluna; ++i) {
 		free( *(string+i) );
 	}

    free(string);
    
    string = NULL;
    
    return 0;
}