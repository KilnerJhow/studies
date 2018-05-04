#include <stdio.h>
#define media (n1, n2, n3) ((n1+n2+n3)/3)

int main() {
    
    float x, y, z, med;
    int count = 0;
    //do{
        scanf("%f%f%f", &x, &y, &z);
    //} while()
    med = media(x,y,z);
    if(x > media) count++;
    if(y > media) count++;
    if(z > media) count++;
    
    printf("%d\n", count);
    return 0;
}