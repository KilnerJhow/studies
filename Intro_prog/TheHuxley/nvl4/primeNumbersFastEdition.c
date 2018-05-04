#include <stdio.h>

int main() {
    
    int limitSup, limitInf, z = 1, prime, aux;

    scanf("%d\n%d", &limitInf, &limitSup);
    if(limitInf > limitSup) {
        int temp = limitSup;
        limitSup = limitInf;
        limitInf = temp;
    }
    prime = limitSup;
    while(prime >= limitInf) {
        
        for(aux = 2; aux <= (limitSup/2); aux++){
            if(prime % aux == 0) z++;
            if(z >= 2) break;
        }
        if(z < 2) {
            if(prime == 1) break;
            printf("%d\n", prime);
        }
        prime--;
        z = 0;
    }

    return 0;
}