#include <stdio.h>

int main() {
    
    int x, y = 0, count;
    do{
        scanf("%d", &x);
        y += x;
        if(x != 0) count++;
        
    } while(x != 0);

    x = y/count;
    if(x < 110) printf("Glicose Normal");
    else if(x >= 110 && x < 200) printf("Glicose Alterada");
    else printf("Glicose Muito Alta");
    
    return 0;
}