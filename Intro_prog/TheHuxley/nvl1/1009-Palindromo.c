#include <stdio.h>

void getInverso(int num) {
    
    int reverse = 0, aux = num;
 
    while(num != 0) {
        reverse *= 10;
        reverse = reverse + num%10;
        num = num/10;
    }
    if(aux == reverse) printf("S");
    else printf("N");
}

int main() {
    
    int num, reverse = 0;
    scanf("%d", &num);
    if(num >= 10000 || num <= 99999) {
        
        getInverso(num);
        //reverse = (num/10000) +(num%10000 - num%1000)/100) + ((num%1000 - num%100)) + ((num%100 - num%10))*100 + (num%10)*10000;
        //if(reverse == num) printf("S");
        //else printf("N");
    }
    else printf("N");
    return 0;
}