#include <stdio.h>

int main() {
    
    int x, y, i;
    scanf("%d%d", &x, &y);
    for(i = x; i <= y; i++) {
        if(i % 5 == 0) {
            printf("%d", i);
            i+=4;
            if(i < y) printf("|");
        }
        
    }
    
    return 0;
}