#include <stdio.h>

int main() {
    
    int aux, num, points = 0;
    
    scanf(" %d",&num);
    if(num == 0) points += 2;
    scanf(" %d",&num);
    if(num == 1) points += 1;
    scanf(" %d",&num);
    if(num == 1) points += 1;
    scanf(" %d",&num);
    if(num == 1) points += 1;
    scanf(" %d", &num);
    if(num == 1) points += 3;
    
    if(points >= 5) {
        printf("A Matrix esta em todo lugar. A nossa volta. E o mundo colocado diante de seus olhos, para que nao veja a verdade. Infelizmente e impossivel dizer o que e a Matrix. Voce tem de ver por si mesmo. *Voce e sugado pelo telefone e revelado a verdade");
    } else {
        printf("Voce precisa entender que a maioria dessas pessoas nao estao prontas para acordar. E muitos estao tao inertes, tao dependentes do sistema que vao lutar para protege-lo");
    }
    
    return 0;
}