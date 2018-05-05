#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <wchar.h>

#define MAX_LINES 7


//Criamos 7 linhas cada uma com capacidade para 100 caracteres que armazenam as informações vindas dos arquivos
wchar_t monitor_lines[MAX_LINES][100];
//Armazena o horário do voo de cada linha - Usado para formatação da saída
wchar_t hour_lines[MAX_LINES][100];

wchar_t flightDetails_lines[MAX_LINES][100];


void manageString();

int main() {

    setlocale(LC_ALL,"");
    wchar_t t = L'ç';
    wchar_t acento[100];

    wcscpy(acento, L"XYZ001 Tóquio 17:50\n");

    printf("%S", acento);
    int i = 0;
    while(acento[i] != L'\0') {
    
        if(acento[i] == L'\n') {
            acento[i] = L'\0';
            acento[i+1] = L'\0';
            printf("\\n found!\n");
            break;
        }
        i++;
    }
    printf("%S", acento);

    // char acento2[100] = "XYZ001 Tóquio 17:50";
    // int i = 0;
    // while(1) {
    //     if(acento[i] == L'\0') {
    //         printf("Terminador!\n");
    //         break;
    //     }
    //     i++;
    // }

    // printf("Terminador indice: %d\n", i);

    // printf("Len: %ld\n", wcslen(acento));
    // printf("Len2: %ld\n", strlen(acento2));

    // // printf("Len: %d\n", strlen("AQT123 Buenos Aires 17:45"));

    // strcpy(monitor_lines[0], "ABC123 Recife 19:00");
    // strcpy(monitor_lines[1], "D34D82 Sao Paulo 18:23");
    // strcpy(monitor_lines[2], "XYZ001 Tóquio 17:50");
    // strcpy(monitor_lines[3], "FFF305 Estocolmo 18:35");
    // strcpy(monitor_lines[4], "GHI456 Lisboa 18:50");
    // strcpy(monitor_lines[5], "DEF321 Nairóbi 19:00");
    // strcpy(monitor_lines[6], "AQT123 Frankfurt 20:00");

    // for(int i = 0; i < strlen(monitor_lines[2]); i++) {
    //     if(monitor_lines[2][i] == t) {
    //         printf("Equal!\n");
    //     }
    // }

    // printf("Size: %ld\n", wcslen((wchar_t*) monitor_lines[2]));

    // for(int i = 1; i < strlen(monitor_lines[2]); i++) {
    //     char c = monitor_lines[2][i];
    //     if(isalpha(c)) {
    //         printf("%c is alphabet\n", c);
    //     } else {
    //         printf("%c is not alphabet\n", c);
    //     }
    // }
    // manageString();


}

void manageString() {

    int i = 1, j;
    wchar_t *ret;
    wchar_t ch = ':';

    for(i = 0; i < MAX_LINES; i++) {
        ret = wcschr(monitor_lines[i], ch);
        //Copiamos apenas o horário do voo para a string de destino
        wcsncpy(hour_lines[i], monitor_lines[i] + wcslen(monitor_lines[i]) - wcslen(ret) - 2, wcslen(monitor_lines[i]) - 5);
        wcsncpy(flightDetails_lines[i], monitor_lines[i], wcslen(monitor_lines[i]) - 5);
        
        printf("Hour lines: %S\n", hour_lines[i]);
        printf("flightDetails: %S\n", flightDetails_lines[i]);

        //O delimitador é o final da string anterior, já que sem isso as vezes partes de outras strings
        //apareciam
        // flightDetails_lines[i][wcslen(monitor_lines[i]) - 5] = '\0';
    }   

}