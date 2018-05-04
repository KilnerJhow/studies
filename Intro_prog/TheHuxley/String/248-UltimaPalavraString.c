#include <stdio.h>

/**
 * This function check if string is different a space or equals a 0 and returns
 */
int checkStr(char str) {
    
    if(str == 0) return 0;
    if(str != ' ') return 1;
    
    return 0;
    
}


void getLastWord(char *str) {
    
    int aux = 0;
    int lastWordPosition = 0, firstWordPosition = 0;



    while(str[aux] != 0) {
        
        
        //If has a space and has a next word, so sets first position, else do nothing
        if(str[aux] == ' ' && checkStr(str[aux + 1])) {
            firstWordPosition = aux + 1;
        }
        aux++;
    }
    //Here were reached the end of string, so subtrate 1 to get last string character
    aux--;
    
    //Here we test if the character in string is a space, if not so set lastPosition
    if(str[aux] != ' ') {
        lastWordPosition = aux;
    } else {
        
        //Else, find the proximous character closest to end
        while(str[aux] == ' ') {
            aux--;
        }
        lastWordPosition = aux;
    }
    
    //Print the characters between firstPosition and lastPosition
    for(aux = firstWordPosition; aux <= lastWordPosition; aux++) {
        printf("%c", str[aux]);
    }
    printf("\n");
}


int main() {
    
    char str[400];
    
    scanf("%[^\n]398s", str);
    
    getLastWord(str);
    
    return 0;
}