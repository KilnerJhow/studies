#include <stdio.h>

void removeEstoque(int estoque[], int pedido, int qntdPedido, int limit) {

	int i, tmp;
	for(i = 0; i < limit; i+=2) {
		if(estoque[i] == pedido) {
			tmp = estoque[i+1];
			tmp -= qntdPedido;
			if(tmp >= 0) {
				estoque[i+1] -= qntdPedido;
				printf("OK\n");
			}
			else printf("ESTOQUE INSUFICIENTE\n");
		}
	}

}

int main() {
    
    int estoque[100];
    int i = 0, pedido, qntdPedido, count = 0, aux = 0;
    
    while(i != 9999) {
    	scanf("%d", &i);
    	if(i != 9999) estoque[count] = i;
    	count++;
    }
    i = 0;
    int count2 = 0;
    while(i != 9999) {

    	scanf("%d", &i);

    	if(aux == 0) aux++;
    	else if(aux == 1) {
    	    pedido = i;
    	    aux++;
    	}
    	else if(aux == 2) {
    		qntdPedido = i;
    		aux++; 
    	} 
    	if(aux == 3) {
    		removeEstoque(estoque, pedido, qntdPedido, count);
    		aux = 0;
    	}
    }

    for(i = 0; i < count-1; i+=2) {
    	printf("%d %d\n",estoque[i], estoque[i+1]);
    }

    return 0;
}