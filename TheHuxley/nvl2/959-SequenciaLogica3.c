#include <stdio.h>

int main() {
    
    int x, y, z;
    int aux = 1, aux2 = 0;
    scanf("%d %d %d", &x, &y, &z);
    
    do {
        if(aux2 < x) {
            printf("%d", aux);
            aux2++;
            aux += z;
            if(aux2 != x) printf(" ");
        } else {
            aux2 = 0;
            printf("\n");
        }
    } while( aux <= y);
    
    
    return 0;
}