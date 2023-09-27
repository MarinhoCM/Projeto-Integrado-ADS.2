/*Elabore um programa em C/C++ que calcule o que deve ser pago por um produto,
considerando o preço normal de etiqueta e a escolha da condição de pagamento.
Utilize os códigos da tabela a seguir para ler qual a condição de pagamento 
escolhida e efetuar o cálculo adequado*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <locale.h>
#include <windows.h>
#include <string.h>

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define END "\e[0;0m"

#define MESSAGE_RED(X) printf("%s %s %s",RED,X,END)
#define MESSAGE_GREEN(X) printf("%s %s %s",GRN,X,END)
#define MESSAGE_YELLOW(X) printf("%s %s %s",GRN,X,END)
#define INFO_MESSAGE(X,Y) printf("%s %s %s %s ",YEL,X,Y,END)

float product_price(void){
	float price;
	MESSAGE_GREEN("Digite o valor do seu produto: ");
	scanf("%f", &price);
	if(price <= 0.0){
		MESSAGE_RED("Digite um valor v�lido!\n");
		product_price();
		return 0.0;
	} else {
		return price;	
	}
}

int menu(void){
	int option;
	MESSAGE_GREEN("Selecione a forma de pagamento:\n");
	MESSAGE_GREEN("\t1 - A vista em dinheiro ou pix, recebe 10%% de desconto.\n");
	MESSAGE_GREEN("\t2 - A vista no cart�o de credito, recebe 5%% de desconto.\n");
	MESSAGE_GREEN("\t3 - Em duas vezes, pre�o normal de etiqueta sem juros.\n");
	MESSAGE_GREEN("\t4 - Em tr�s vezes, pre�o normal de etiqueta mais juros de 10%%.\n");
	MESSAGE_GREEN("\t5 - Sair.\n");
	MESSAGE_GREEN("\t-----> ");
	scanf("%i", &option);	
	return option;
}

float calculator(int option, float price){
	float total, discount;
	switch(option){
		case 1:
			discount = price * 0.1;
			total = price - discount;
			INFO_MESSAGE("O valor do seu produto � R$ %.2f", total);
			break;
		case 2:
			discount = price * 0.05;
			total = price - discount;
			INFO_MESSAGE("O valor do seu produto � R$ %.2f", total);
			break;
		case 3:
			total = price / 2;
			INFO_MESSAGE("O seu produto ter� duas parcelas de R$ %.2f", total);
			break;
		case 4:
			total = price / 3;
			INFO_MESSAGE("O seu produto ter� tr�s parcelas de R$ %.2f", total);
			break;
	}
}

int main(void){
	setlocale(LC_ALL, "");
	float price = product_price();
	int option = menu();
	if (option == 5){
		return 0;
	} else if (option < 0 || option == 0 ||option >= 6){
		MESSAGE_YELLOW("Digite uma op��o v�lida!\n");
		int option = menu();
	}
	calculator(option, price);
    return 0;
}
