#include <stdio.h>


int main() {
    
    double x, i = 1, z = 2, aux = 0;
    scanf("%lf", &x);
    //only contains the decimal number
    do {
        
        while((i/z) != x) {
            i++;
            if(i > 100) break;
        }
        if((i/z) == x) break;
        z++;
        i = 1;
    }while(1);
    printf("%.0lf/%.0lf\n", i, z);
    
    return 0;
}