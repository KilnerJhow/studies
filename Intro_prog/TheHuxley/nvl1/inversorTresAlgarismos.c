#include <stdio.h>

int main() {
    
    int x, y = 10;
    scanf("%d", &x);
    y = (x%10)*100 + (x%100-x%10) + x/100;
    printf("%d", y);
    
    return 0;
}