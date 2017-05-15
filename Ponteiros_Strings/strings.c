#include <stdio.h>
#define true 1
#define false 0


int stringLength(const char *str) {
    
    int i = 0;
    for(; str[i] != '\0'; i++);
    
    return i;
}

//String constant for not change its value
//Precaution
int stringComparison(const char *str1, const char *str2) {
    
    int i;
    for(i = 0; str1[i] == str2[i]; i++) {
        if(str1[i] == '\0') return true;
    }
    
    return false;
    
}


int main() {
    
    char string[] = "hello1";
    char string1[] = "hello";
    
    printf("String %s de tamanho %d\n", string, stringLength(string));
    
    printf("String %s e %s são", string, string1);
    
    if(stringComparison(string, string1))  printf(" iguais\n");
    else printf(" diferentes\n");
    
    
    return 0;
}