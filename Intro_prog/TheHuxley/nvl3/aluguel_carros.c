#include <stdio.h>

int main() {
    
    int x, y, z;
    scanf("%d\n%d", &x, &y);
    if(x == 1 && y <= 100) x = 90;
    else {
        if(y > x*100) y = (y - x*100)*12;
        else y = 0;
        x = x*90 + y;
    }
    printf("%d.00", x);
    
    
    return 0;
}