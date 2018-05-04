/**
 * Aluno: Jonathan Kilner
 * Criado em 26/04/2017
 * TODO: Terminar
 * 
*/
#include <stdio.h>
#define S0 0
#define S1 1
#define S2 2
#define S3 3
#define S4 4
#define S5 5
#define S6 6
#define S7 7
#define S8 8
#define S9 9
#define S10 10
#define S11 11
#define S12 12
#define SE 22

#define ehDigito(c) (c >= '0' && c <= '9')
#define ehLetra(c) (c >= 'a' && c <='z' || c >= 'A' && c <= 'Z' || c == '_')


int toState(int estado, char leitura) {
    int proximoEstado = estado;
    switch(estado) {
        
        case S0:
            if(ehDigito(leitura)) proximoEstado = S1;
            break;
        case S1:
            if(leitura == '.') proximoEstado = S2;
            else if(leitura >= '0' && leitura <= '9') proximoEstado = S1;
            else proximoEstado = S10;
            break;
        case S2:
            
            break;
        case S3:
            break;
        case S4:
            break;
        case S5:
            break;
        case S6:
            break;
        case S7:
            break;
        case S8:
        
            break;
        case S9:
        
            break;
        case S10:
        
            break;
        case S11:
            
            break;
        case S12:
        
            break;
        default:
            proximoEstado = SE;
            break;
    }
    return proximoEstado;
}


int main() {
    
    char leitura;
    int estado = S0;
    scanf(" %c", &leitura);
    
    while(leitura != '*' && estado != SE) {
        
        estado = toState(estado, leitura);
        scanf(" %c", &leitura);
    }

}