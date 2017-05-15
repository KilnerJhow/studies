#include <stdio.h>

int main() {
    
   int n, aux;
   double x, y, sumXn = 0, sumYn = 0, sumX2n = 0, sumXYn = 0;
   double delta, A, B;
   
   scanf("%d", &n);
   aux = n;
   do {
       scanf("%lf %lf", &x, &y);
       
       sumXn += x;
       sumYn += y;
       sumXYn += (x*y);
       sumX2n += (x*x);
       n--;
   } while(n > 0);
    printf("SumXN: %lf\n", sumXn);
    printf("SumYN: %lf\n", sumYn);
    printf("SumXYN: %lf\n", sumXYn);
    printf("SumX2N: %lf\n", sumX2n);
    
    n = aux;
    delta = n*sumX2n - (sumXn*sumXn);
    A = (n*sumXYn - sumXn*sumYn)/delta;
    B = (sumX2n*sumYn - sumXn*sumXYn)/delta;
    
    printf("A: %.2lf\n", A);
    printf("B: %.2lf\n", B);
    
    return 0;
}