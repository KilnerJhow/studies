#include <stdio.h>
#include <stdlib.h>


int main() {
    
    float x, y, z;
    
    scanf("%f %f %f", &x, &y, &z);
    
    
    if( (x < y && x < z && y < z) || (x > y && x > z && y > z) ) {
        printf ("true");
    } else {
        printf ("false");
    }
    
    return 0;
}