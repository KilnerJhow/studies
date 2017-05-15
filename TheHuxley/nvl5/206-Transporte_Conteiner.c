#include <stdio.h>

int main() {
    
    int a, b, c, volumeConteiner;
    int x, y, z, volumeNavio;
    int qtdConteiner;
    
    scanf("%d%d%d", &a, &b, &c);
    scanf("%d%d%d", &x, &y, &z);
    
    volumeConteiner = a*b*c;
    volumeNavio = x*y*z;
    
    qtdConteiner = volumeNavio/volumeConteiner;
    
    printf("%d\n", qtdConteiner);
    
    return 0;
}