#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	srand(time(NULL));

	int valorMinim, valorMaxim, aux, mitjana, lectura = 1, pujades = 0, valor, valorTotal = 0, alertes = 0;
	char lletra;

	printf("Добро пожаловать в реактор 4 товарищ\n");
	printf("Desitja iniciar la prova de seguretat? (S/N): ");
	scanf(" %c", &lletra);

	if (lletra == 'S' || lletra == 's')
	{

		do
		{
			printf("Introdueixi el valor mínim acceptable per la prova (1..10):\n");
			scanf("%d", &valorMinim);
		} while (valorMinim < 1 || valorMinim > 10);

		do
		{
			printf("Introdueixi el valor màxim acceptable per la prova (1..10):\n");
			scanf("%d", &valorMaxim);
		} while (valorMaxim < 1 || valorMaxim > 10);

		if (valorMinim > valorMaxim)
		{
			aux = valorMinim;
			valorMinim = valorMaxim;
			valorMaxim = aux;
		}

		printf("Generant lectures...\n");
		Sleep(2000);

		while (lectura <= 25 && pujades <= 3)
		{
			valor = (rand() % (valorMaxim - valorMinim + 1)) + valorMinim;
			valorTotal = valorTotal + valor;
			mitjana = valorTotal / lectura;
			if (valor <= mitjana)
			{
				setColor(LIGHTGREEN);
				printf("[%02d] Valor per sota de la mitjana: %d\n", lectura, valor);
				pujades = 0;
			}
			else
			{
				setColor(LIGHTRED);
				printf("[%02d] Valor per sobre de la mitjana: %d\n", lectura, valor);
				pujades++;
			}
			if (pujades == 3)
			{
				printf("WARNING: Неизбежное расплавление ядра\n");
				alertes++;
			}
			if (pujades == 4)
			{
				printf("!!! EXPLOSIÓ DEL REACTOR 4 !!!\n");
			}
			lectura++;
			Sleep(1000);
		}

		setColor(GREY);
		printf("\nTotal de lectures realitzades: %d\n", lectura - 1);
		printf("Total Alertes de fusió del nucli: %d", alertes);
	}
	else
	{
		printf("Fi de la prova de seguretat.");
	}
	acabament();
	return 0;
}
