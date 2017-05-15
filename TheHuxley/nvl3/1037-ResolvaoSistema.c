#include <stdio.h>

int main() {
    
    float arr[1000];
    int x, count = 0;
    int qtdVariaveis;
    
    scanf("%d", &qtdVariaveis);
    while(scanf("%d", &x) != EOF) {
        arr[count] = x;
        count++;
    }
    
    
    
    
    return 0;
}