#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fatorial(double n) {
    int i;
    double x = 1;
    if (n == 0 || n == 1) return 1;
    for(i = n; i > 1; i--){
        x *= i;
    }
    return x;
}

double exponeciancao(double x, int expoente) {
    int n;
    double aux = x;
    if (expoente == 0) return 1;
    else {
        for(n = expoente; n > 1; n--){
            x*=aux;
        }
    }
    return x;
}

int main() {

    double x = 0, sumAt = 0, sumAnt = 1, aux = 2;
    int n = 0;
    scanf("%lf", &x);

    do{
        if(n % 2 == 0) aux = 1;
        else aux = -1;
        sumAnt = sumAt;
        sumAt += (aux/fatorial(2*n))*exponeciancao(x, 2*n);
        n++;
    }while(fabs(sumAt - sumAnt) > 0.00001);
    printf("%.2lf\n", sumAt);

    return 0;
}
