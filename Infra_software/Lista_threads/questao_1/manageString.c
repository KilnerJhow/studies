#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <wchar.h>

#define MAX_LINES 7


//Criamos 7 linhas cada uma com capacidade para 100 caracteres que armazenam as informações vindas dos arquivos
char monitor_lines[MAX_LINES][100];
//Armazena o horário do voo de cada linha - Usado para formatação da saída
char hour_lines[MAX_LINES][100];

char flightDetails_lines[MAX_LINES][100];


void manageString();

int main() {

    setlocale(LC_ALL,"");

    // printf("Len: %d\n", strlen("AQT123 Buenos Aires 17:45"));

    strcpy(monitor_lines[0], "ABC123 Recife 19:00");
    strcpy(monitor_lines[1], "D34D82 Sao Paulo 18:23");
    strcpy(monitor_lines[2], "XYZ001 Tóquio 17:50");
    strcpy(monitor_lines[3], "FFF305 Estocolmo 18:35");
    strcpy(monitor_lines[4], "GHI456 Lisboa 18:50");
    strcpy(monitor_lines[5], "DEF321 Nairóbi 19:00");
    strcpy(monitor_lines[6], "AQT123 Frankfurt 20:00");

    printf("Size: %d\n", wcslen((wchar_t*) monitor_lines[2]));

    for(int i = 1; i < strlen(monitor_lines[2]); i++) {
        char c = monitor_lines[2][i];
        if(isalpha(c)) {
            printf("%c is alphabet\n", c);
        } else {
            printf("%c is not alphabet\n", c);
        }
    }
    manageString();


}

void manageString() {

    int i = 1, j;
    char *ret;
    char ch = ':';
    char dest[100];
    int max_strlen = 25, i_max_strlen = 0;

    for(i = 0; i < MAX_LINES; i++) {
        ret = strchr(monitor_lines[i], ch);

        if(max_strlen < strlen(monitor_lines[i])) {
            max_strlen = strlen(monitor_lines[i]);
            i_max_strlen = i;
        }

        //Copiamos apenas o horário do voo para a string de destino
        strncpy(hour_lines[i], monitor_lines[i] + strlen(monitor_lines[i]) - strlen(ret) - 2, strlen(monitor_lines[i]) - 5);
        strncpy(flightDetails_lines[i], monitor_lines[i], strlen(monitor_lines[i]) - 5);
        
    }
    int k = strlen(monitor_lines[i_max_strlen]);
    printf("%s - %d\n", monitor_lines[i_max_strlen], k);
    printf("Max strlen: %d\n", max_strlen);
    int aux;
    for(i = 0; i < MAX_LINES; i++) {

        printf("%s", flightDetails_lines[i]);
        aux = max_strlen - strlen(monitor_lines[i]);
        j = 0;
        while(j < aux) {
            printf(" ");
            j++;
        }
        // printf("%s - strlen(monitor[%d]) = %d - aux = %d\n", hour_lines[i], i, strlen(monitor_lines[i]), aux);

    }
    

}