#include <stdio.h>

int main() {
    
    int x, y, count = 0;
    
    scanf("%d %d", &x, &y);
    
    if(x >= 150 && y >= 12) count++;
    if(x >= 140 && y >= 14) count++;
    if(x >= 170 || y >= 16) count++;
    
    printf("%d\n", count);
    
    return 0;
}