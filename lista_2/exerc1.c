#include <stdio.h>


int main() {

    float x = 0.04;
    double y = 0.32;
    long double z = 0.00003;
    
    
    printf("%f %f %Lf\n",  x, y, z);
    
    printf("%e %e %Le ", x, y, z);
    
    
    
}