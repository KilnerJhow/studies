#include <stdio.h>

int main() {
    
    int array[5], i, flag = 0, aux = 0;
    
    do{
        scanf("%d", &i);
        flag++;
    } while(flag != 5)
    
    /*for(i = 0; i < 5; i++) {
        scanf("%d", &array[i]);
    }
    for(i = 1; i < 5; i++) {
        if(array[i - 1] <= array[i]) flag++;
        else flag--;
    }*/
    
    if(flag == 4) printf("C");
    else if(flag == -4) printf("D");
    else printf("N");
    
    return 0;
}