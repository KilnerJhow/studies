#include <stdio.h>

int main() {
    
    double a, b;
    scanf("%lf%lf", &a, &b);
    a *= 3.5;
    b *= 7.5;
    printf("MEDIA = %.5lf\n", (a+b)/11);
    
    return 0;
}