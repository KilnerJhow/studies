#include <stdio.h>

int addPedido(int arr[], int i) {
    
    scanf("%d", &arr[i]);
    i++;
    return i;
}

void removePedido(int arr[], int i, int pedidoRemovido) {
    
    int j = 0, removido = 0;
    for(; j < i; j++) {
        if(arr[j] == pedidoRemovido) {
            arr[j] = 0;
            removido = 1;
        }
    }
    if(removido) printf("removido\n");
    else printf("falha\n");
    
    
}

void printPedidos(int arr[], int i) {
    
    int j = 0, aux = 1, aux1 = 0;
    for(; j < i; j++) {

        if(arr[j] == 0){
          aux1++;
          continue;
        } 
        else {
            printf("%*d",aux, arr[j]);
            if(aux < 2) aux++;
            
        }
    }

    if(aux1 == j) printf("vazia");
    printf("\n");
    
}

int main() {
    
    char pedido;
    int tipoPedido[10000], i = 0, aux;
    
    while(scanf(" %c", &pedido) != EOF) {
        
        
        if(pedido == 'a') {
            i = addPedido(tipoPedido, i);
        }
        else if(pedido == 'r') {
            scanf("%d", &aux);
            removePedido(tipoPedido, i, aux);
        }
        else if(pedido == 'p') {
            printPedidos(tipoPedido, i);
        }

    }
    
    return 0;
}