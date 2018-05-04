#include <stdio.h>


int main() {
    
    int duasQuestoes, primeiraQuestao, umaQuestao, nenhumaQuestao;
    int primeiraQ, segundaQ, total;
    
    scanf("%d", &duasQuestoes);
    scanf("%d", &primeiraQuestao);
    scanf("%d", &umaQuestao);
    scanf("%d", &nenhumaQuestao);
    
    primeiraQ = primeiraQuestao - duasQuestoes;
    segundaQ = umaQuestao - primeiraQ;
    total = primeiraQ + segundaQ + nenhumaQuestao + duasQuestoes;
    printf("%d\n", total);
    
    
    
    return 0;
}