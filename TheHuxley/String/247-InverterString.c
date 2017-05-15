#include <stdio.h>
#include <string.h>
#define TAM_MAX 255
/**
 * This Function inverts the string passed by
 */
void inverteString(char *str) {
    
    //Store the value pointed by str, its the string that passed to function;
    char *i = str;
    
    //Creates another string with tam max previously defined
    char j[TAM_MAX];
    
    //Copy a instance of string str to string j
    strcpy(j, str);
    
    //Our counter
    int k = 0;
    
    //Minus 1 because array starts in 0
    int strLenFinal = strlen(str) - 1;
    
    //Get the lenght of string
    int strLenInicial = strlen(str);
    
    for(; k < strLenInicial; k++, strLenFinal--) {
        
        //Get the last value of string j and assign to string i
        i[k] = j[strLenFinal];

    }
    
    //Adds the delimiter string to the final o string i
    i[k] = 0;
}

int main() {
    
    char str[255];
    
    scanf("%[^\n]253s", str);
    
    inverteString(str);
    
    printf("%s\n", str);
    
    return 0;
}