/**
 *  Student: Jonathan Kilner
 *  Finalized in: 08/05/17
 * 
 *  This program get a String and tell if the string is palindrome or not 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 255

int ehPalindromo(const char *src, const char *dest);
void eliminaEspacosBrancos(char *str);
void inverteString(char *str);
void toLowerCase(char *str);


int main() {

    char str[TAM_MAX], copyString[TAM_MAX];
    
    //Get the value from user
    scanf("%[^\n]253s", str);

    //Convert all uppercase letters to lowercase
    toLowerCase(str);

    //trim the whitespace of the string
    eliminaEspacosBrancos(str);

    //Realize a copy of str and store it on copyString
    strcpy(copyString, str);
    
    //Inverts str
    inverteString(str);
    
    //Compare str and copyString, if equals so its is palindrome else, not.
    if(ehPalindromo(str, copyString)) {
        printf("Is Palindrome\n");
    } else {
        printf("Isn't Palindrome\n");
    }
    
    return 0;
}




/**
 *  This function trim the whitespaces presents in a String 
 */
void eliminaEspacosBrancos(char *str) {
    
    //Creates 2 pointers that contains the string
    char *i = str;
    char *j = str;
    
    //While the j pointer is different to the final string character
    while(*j != 0) {
        
        //Store the value pointed by j in value pointed by i and increment j
        *i = *j++;
        
        //If the value pointed by i is different from a whitespace, then increment i, else continues the loop
        if(*i != ' ') i++;
        
        //So the whitespace is jumped and the next character is stored in the local
    }
    //Adds the final string delimiter
    *i = 0;
    
}

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

/**
 * This function transforms all letters in lowercase
 */
void toLowerCase(char *str) {
    
    int i = 0;
    //Get the lenght of string
    int j = strlen(str);
    
    //
    for(i = 0; i < j; i++) {
      
      //If has uppercase letters, so convert it to lowercase  
        if(str[i] >= 'A' && str[i] <= 'Z'){ 
            
            //Get the value of str[i] and sums 32 because of ASCII Table
            str[i] = str[i] + 32;
        
            //Example: a = '97', A = '65' => a - A = 32
            //b = '98', B = 66 => b - B = 32
        }
    }
}

/**
 * This function compares two strings and return 1 if true else not, 0
 */
int ehPalindromo(const char *src, const char *dest) {
    
    int i = 0;
    
    if(strcmp(src, dest) == 0) return 1;
    return 0;
}
