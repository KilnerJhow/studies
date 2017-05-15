#include <stdio.h>

void par(int x, int limit) {

    if(x >= limit) {
        if(limit % 2 == 0) printf("%d\n", limit);
        return;
    }
    printf("%d\n", x);
    par(x + 2, limit);

}

int main() {
    
    int x; 
    scanf("%d", &x);
    par(0, x);
    return 0;
}