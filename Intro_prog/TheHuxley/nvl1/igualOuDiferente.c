#include <stdio.h>

int main() {
    
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    
    if(x == y && x == z && y == z) printf("1");
    else if(x == y || x == z || y == z) printf("3");
    else printf("2");
    
    return 0;
}