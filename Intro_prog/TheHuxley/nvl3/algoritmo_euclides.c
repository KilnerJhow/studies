#include <stdio.h>

int mdc(int a, int d) {
    
    int x, resto, mdc1;
    resto = a%d;
    if(resto == 0) {
        mdc1 = d;
        return mdc1;
    } else {
        mdc1 = mdc(d, resto);
    }
    
}

int main() {
    
    int x, y, z;
    scanf("%d", &z);
    do{
        scanf("%d%d", &x, &y);
        printf("MDC(%d,%d) = %d\n", x, y, mdc(x,y));
        z--;
    } while (z != 0);
    return 0;
}