#include <stdio.h>

int main() {
    
    int x, y = 10;
    scanf("%d", &x);
    y = x%10;
    x /= 10;
    y = y*10 + x;
    printf("%d", y);
    
    return 0;
}