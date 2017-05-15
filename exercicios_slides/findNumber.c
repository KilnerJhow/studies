#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    int x, y, aux = 10;
    
    srand(time(NULL));
    
    printf("%d %d",x,y);
    do {
        aux = 10;
        x = rand()%90 + 10;
        y = rand()%90 + 10;
        
        while(y <= aux) {
            aux *= 10;
        }
        
        int sum = x+y;
        if((sum*sum) == (x*aux + y)) {
            printf("True, Numbers: %d %d", x, y);
            aux = 1;
        } else {
            //printf("False");
        }
    } while(aux != 1);
}