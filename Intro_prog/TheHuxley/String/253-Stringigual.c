#include <stdio.h>
#include <string.h>


int main() {
    
    char str1[50], str2[50];
    
    scanf("%49s", str1);
    scanf("%49s", str2);
    
    if(strcmp(str1, str2)) printf("DIFERENTES\n");
    else printf("IGUAIS\n");
    
    
    return 0;
}