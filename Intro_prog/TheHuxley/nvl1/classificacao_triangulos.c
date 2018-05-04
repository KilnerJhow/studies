#include <stdio.h>

int main() {
    
    double x, y, z;
    scanf("%lf%lf%lf", &x, &y, &z);
    
    if(x == y && y == z) {
        printf("equilatero\n");
    } else if(x == y || x == z || y == z) {
        printf("isosceles\n");
    } else {
        printf("escaleno\n");
    }
    
    return 0;
}