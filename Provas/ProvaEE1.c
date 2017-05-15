/****
*	Aluno: Jonathan Kilner dos Santos Silva
*/


#include <stdio.h>

/**
*	Valida a entrada do valor dos meses de pagamento
*/
int validaMesesPagamento() {
	int mesesPagamento;

	printf("Quantidade de meses de pagamento incorreta, digite novamente: ");
	scanf("%d", &mesesPagamento);
	return mesesPagamento;
}


/**
*	Valida a entrada da data de pagamento
*/
int validaData(int dia, int mes, int ano) {

	int aux = 0;

	if(mes > 12) return 1;

	switch(mes) {
		case 1:
			if(dia > 31) aux = 1;
			break;
		case 2:
			if(dia > 28) aux = 1;
			break;
		case 3:
			if(dia > 31) aux = 1;
			break;
		case 4:
			if(dia > 30) aux = 1;
			break;
		case 5:
			if(dia > 31) aux = 1;
			break;
		case 6:
			if(dia > 30) aux = 1;
			break;
		case 7:
			if(dia > 31) aux = 1;
			break;
		case 8:
			if(dia > 31) aux = 1;
			break;
		case 9:
			if(dia > 30) aux = 1;
			break;
		case 10:
			if(dia > 31) aux = 1;
			break;
		case 11:
			if(dia > 30) aux = 1;
			break;
		case 12:
			if(dia > 31) aux = 1;
			break;
	}

	return aux;
}


/**
*	Valida a entrada do valor do pagamento realizado
*/
double validaPagamento(double montante, double valorPago) {

	double valorMinimo = 0.1*montante;
	while(valorPago > montante || valorPago < valorMinimo){
		printf("Valor de pagamento incorreto, digite novamente o valor: ");
		scanf("%lf", &valorPago);
	}
	return valorPago;
}

/**
*	Valida a entrada do valor do montante
*/
double validaMontante(double montante) {
	while(montante < 0) {
		printf("Valor Incorreto, digite novamente o valor do montante: ");
		scanf("%lf", &montante);
	}
	return montante;
}


/***
*	Calcula o valor do montante adicionado aos juros mensal
*
*/
double valorMensalidadeFutura(double montante, double juros, int meses) {

	int aux = 0;
	//Calcula o valor do montante de acordo com a quantidade de meses
	while (aux < meses) {
		montante = montante + montante*juros;
		aux++;
	}

	return montante;
}

/**
*	Calcula a data futura no qual o boleto será pago
*
*/
int imprimeDataFutura(int dia, int mes, int ano, int meses) {

    //Caso o mês de pagamento caia em fevereiro
    if(mes == 2 && dia > 28) {
        dia = 28;
    }
    //Imprime na tela a data de pagamento, respeitando a data anterior paga
	printf("%d/%d/%d", dia, mes, ano);
	mes++;
	return mes;
}

/**
*	Função que recebe a data e o valor a ser pago e imprime os valores que irão ser pagos e suas respectivas datas
*
*/
void imprimeBoletos(double valorParcelado, int mesesPagamento, int diaPagamento, int mesPagamento, int anoPagamento) {
	printf("Seus pagamentos futuros serao: \n");
	int mesesAuxiliar = 0;
	double taxaJuros = 0.132;
	//Adiciona 1 para não haver o segundo pagamento no mesmo mês do primeiro pagamento
	while(mesesAuxiliar < mesesPagamento) {
        mesesAuxiliar++;

        //Imprime o mesmo dia para a data
		mesPagamento = imprimeDataFutura(diaPagamento, mesPagamento, anoPagamento, mesesPagamento);
		printf("\t R$ %5.2lf\n", valorMensalidadeFutura(valorParcelado, taxaJuros, mesesAuxiliar));
        if(mesPagamento > 12) {
                anoPagamento++;
                mesPagamento = 1;
        }

	}
}

int main() {

    int mesesPagamento, diaPagamento, mesPagamento, anoPagamento;
	double montante, valorPago, valor_Pagar ;

	//Pega o valor total do montante do usuário
	printf("Qual o valor total da fatura? ");
	scanf("%lf", &montante);

	//Valida esse valor
	montante = validaMontante(montante);

	//Pergunta data de pagamento ao usuário
	printf("Qual a data do pagamento? ");
	scanf("%d/%d/%d", &diaPagamento, &mesPagamento, &anoPagamento);

	//Valida a data
	while(validaData(diaPagamento, mesPagamento, anoPagamento)) {
		printf("Data incorreta, digite novamente: ");
		scanf("%d/%d/%d", &diaPagamento, &mesPagamento, &anoPagamento);
	}

	//Informa ao usuário o valor mínimo a ser pago
	printf("Valor minimo a ser pago: R$ %.2lf\n", montante*0.1);

	//Pergunta ao usuário qual o valor que ele deseja pagar
	printf("Qual o valor do pagamento a vista? ");
	scanf("%lf", &valorPago);


	//Valida esse valor
	valorPago = validaPagamento(montante, valorPago);

	//Caso o valor seja igual ao montante, o programa agradece e encerra
	if((montante - valorPago) == 0) {
		printf ("Obrigado pelo pagamento! Volte sempre!\n");
	}
	//Caso contrário ele passa para a impressão das datas e dos valores
	else {
		//valor que o usuário ainda deve pagar
		valor_Pagar = montante - valorPago;

		//Pergunta ao usuário em quantos meses ele pretende pagar o valor restante
		printf("Em quantos meses voce pretende pagar o restante de: R$: %.2lf? ", valor_Pagar);
		scanf("%d", &mesesPagamento);

		//valida os meses que o usuário digitou
	 	while(mesesPagamento < 1 || mesesPagamento > 12) mesesPagamento = validaMesesPagamento();

	 	//Divide o valor total pela quantidade de meses, a fim de retornar uma base para o pagamento
	 	valor_Pagar /= mesesPagamento;

	 	//imprime os boletos coms as datas e os valores correspondentes
	 	imprimeBoletos(valor_Pagar, mesesPagamento, diaPagamento, mesPagamento+1, anoPagamento);
	}
    return 0;
}
