#include <iostream>
#include <stdio.h>
#include <locale.h>



int main()
{
    setlocale(LC_NUMERIC, "pt_BR");
    
	double salarioBruto, salarioLiquido, INSS, FGTS, horas, quantHoras, impostoRenda, porIr, desconto;

	//Pede as informaC'oes do valor da hora e a quantidade trabalhada
	std:: cout << "Por favor, informe o valor da sua hora: ";
	std:: cin >> horas;
	std:: cout << "\n";

	std:: cout << "Por favor, informe a quantidade de horas trabalhadas: ";
	std:: cin >> quantHoras;
	std:: cout <<  "\n";

	//calculo salarioBruto
	salarioBruto = horas * quantHoras;

	//Calculo imposto de renda
	if(salarioBruto <= 900) {
		impostoRenda = 0;
		porIr = 0;

	}
	else if(salarioBruto <= 1500) {
		impostoRenda = (salarioBruto * 5) /100;
		porIr = 5;
	}
	else if(salarioBruto <= 2500) {
		impostoRenda = (salarioBruto * 10) / 100;
		porIr = 10;

	}
	else if(salarioBruto > 2500) {
		impostoRenda = (salarioBruto * 20) / 100;
		porIr = 20;

	}

	// Calculo INNS e FGTS
	INSS = (salarioBruto * 10) / 100;
	FGTS = (salarioBruto * 11) / 100;

	//Calculo do desconto
	desconto = impostoRenda + INSS;

	//Calculo salario Liquido
	salarioLiquido = salarioBruto - desconto;

	//ImpreC'ao dos resultados

	printf("Salario Bruto(%.f*%.f) R$%.2f\n", horas, quantHoras, salarioLiquido);
	printf("(-)IR (%.f%%): R$%.2f\n", porIr, impostoRenda);
	printf("(-)INSS (10%%): R$%.2f\n", INSS);
	printf("FGTS (11%%): R$%.2f\n", FGTS);
	printf("Total desconto: R$%.2f\n", desconto);
	printf("Salario Liquido: R$%.2f\n", salarioLiquido);


	return 0;
}