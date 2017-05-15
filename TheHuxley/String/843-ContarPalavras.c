#include <stdio.h>
#include <string.h>


/**
 * This function check if string is different a space or equals a 0 and returns
 */
int checkStr(char *str) {
    
    if(*str == 0) return 0;
    if(*str != ' ') return 1;
    
    return 0;
    
}


/**
 * This function get the quantity of words in a string
 */
int contaPalavras(char *str) {

    int countPalavras = 0;

    //Run while until final marker string
    while(*str != 0) {
        
        //If has a space, check if before this space have a word
        //If yes, so count +1 word
        if(*str == ' ') {
            if(checkStr(str - 1)) countPalavras++;
        }
        
        //Increment to another memory position
        str++;
    }
    
    //if the last character is different to a 0 or space, increment +1
    if(checkStr(str-1)) {
        countPalavras++;
    }
    
    
    //return the quantity of words
    return countPalavras;
}



int main() {
    
    char str[500];
    
    scanf("%[^\n]498s", str);
    
    printf("%d\n", contaPalavras(str));

    
    return 0;
}