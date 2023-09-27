/*Elabore um programa em C/C++ que calcule o que deve ser pago por um produto,
considerando o preço normal de etiqueta e a escolha da condição de pagamento.
Utilize os códigos da tabela a seguir para ler qual a condição de pagamento 
escolhida e efetuar o cálculo adequado*/

#include <stdio.h>
#include <iostream>
#include <locale>

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define END "\e[0;0m"

#define MESSAGE_RED(X) printf("%s %s %s",RED,X,END)

float product_price(void){
	float price;
	printf("Digite o valor do seu produto: ");
	scanf("%f", &price);
	if(price <= 0.0){
		printf("Digite um valor válido!\n");
		product_price();
		return 0.0;
	} else {
		return price;	
	}
}

int menu(void){
	int option;
	printf("Selecione a forma de pagamento:\n");
	printf("\t1 - A vista em dinheiro ou pix, recebe 10%% de desconto.\n");
	printf("\t2 - A vista no cartão de credito, recebe 5%% de desconto.\n");
	printf("\t3 - Em duas vezes, preço normal de etiqueta sem juros.\n");
	printf("\t4 - Em três vezes, preço normal de etiqueta mais juros de 10%%.\n");
	printf("\t5 - Sair.\n");
	printf("\t-----> ");
	scanf("%i", &option);	
	return option;
}

float calculator(int option, float price){
	float total, discount;
	switch(option){
		case 1:
			discount = price * 0.1;
			total = price - discount;
			printf("O valor do seu produto é R$ %.2f", total);
			break;
		case 2:
			discount = price * 0.05;
			total = price - discount;
			printf("O valor do seu produto é R$ %.2f", total);
			break;
		case 3:
			total = price / 2;
			printf("O seu produto terá duas parcelas de R$ %.2f", total);
			break;
		case 4:
			total = price / 3;
			printf("O seu produto terá três parcelas de R$ %.2f", total);
			break;
	}
}

int main(void){
	setlocale(LC_ALL, "");
	float price = product_price();
	int option = menu();
	if (option == 5){
		return 0;
	} else if (option == 0 || option >= 6){
		printf("Digite uma opção válida!\n");
		int option = menu();
	}
	calculator(option, price);
    return 0;
}
