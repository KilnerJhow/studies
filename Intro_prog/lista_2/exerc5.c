#include <stdio.h>



int main() {
    
    char ano[4], dia[2], mes[2], i = 0;
    char data[11];

    printf("Insira uma data no formato dd/mm/aaaa: ");
    scanf("%10s", data);
    
    
    for(i = 0; i < 4; i++) ano[i] = data[i + 6];
    for(i = 0; i < 2; i++) {
        dia[i] = data[i];
        mes[i] = data[i+3];
    }
    
}