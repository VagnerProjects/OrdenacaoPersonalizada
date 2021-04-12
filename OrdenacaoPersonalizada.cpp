#include<stdio.h>
#include <locale.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <cstdio>
#include <ctime>
#include <list>
#include <string>

using namespace std;

void quickSortDecrescente(int arr[], int low, int high);
void ordenaBolhaCrescente(int vetorSize, int arrayOrdena[]);
void quickSortCrescente(int arr[], int low, int high, int opc);
void ordenaBolhaDecrescente(int vetorSize, int arrayOrdena[]);
void ordenaSelecaoDecrescente(int arrayOrdena[], int vetorSize);
void ordenaSelecaoCrescente(int arrayOrdena[], int vetorSize);
int partitionCrescente(int arr[], int low, int high);
void ordenaInsercaoCrescente(int vetorSize, int arrayOrdena[]);
void ordenaInsercaoDecrescente(int vetorSize, int arrayOrdena[]);
void menu();
void swap(int* a, int* b);
void preencherVetor(int vetorSize);
void menuOrdena(int opcaoAlg, int vetorSize);
void printArray(int arr[], int size, int modo);
void ordenaBolhaPares(int vetorSize, int arrayOrdena[]);
void ordenaBolhaImpares(int vetorSize, int arrayOrdena[]);
void ordenaInsercaoPares(int vetorSize, int arrayOrdena[]);
void ordenaInsercaoImpares(int vetorSize, int arrayOrdena[]);
void ordenaSelecaoPares(int arrayOrdena[], int vetorSize);
void ordenaSelecaoImpares(int arrayOrdena[], int vetorSize);
void ordenaBolhaPrimos(int vetorSize, int arrayOrdena[]);
void ordenaInsercaoPrimos(int vetorSize, int arrayOrdena[]);

int vetor[100];

int main()
{
	menu();

	system("pause");
	return 0;
}

void menu()
{
	setlocale(LC_ALL, "portuguese");
	int vetorSize = sizeof vetor / sizeof vetor[0];
	int opcao;
	preencherVetor(vetorSize);

	do
	{

		system("cls");
		cout << endl;

		cout << " BEM VINDO AO PROGRAMA DE ORDENACAO DE VETORES" << endl;
		cout << "=========================================================" << endl << endl;

		cout << " Escolha uma opcao para comecar" << endl << endl;

		cout << " 00 - Bluble Sort" << endl;
		cout << " 01 - Insertion Sort" << endl;
		cout << " 02 - Select Sort" << endl;
		cout << " 03 - Quick Sort" << endl;
		cout << " 05 - Sair" << endl << endl;

		cout << " Escolha: ";
		cin >> opcao;
		fflush(stdin);

		cout << endl << endl;
		cout << " Carregando..." << endl;

		if (opcao > 5)
		{
			cout << endl << endl;
			cout << "Escolha uma opcao valida" << endl << endl;
			cout << " Carregando..." << endl << endl;

			Sleep(2000);
			continue;
		}

		Sleep(2000);

		if (opcao == 5)
			exit(0);


		menuOrdena(opcao, vetorSize);

	} while (opcao != 5);
}

void menuOrdena(int opcaoAlg, int vetorSize)
{
	setlocale(LC_ALL, "Portuguese");
	int opcao;

	do
	{
		system("cls");
		cout << endl;
		string algoritmo = "";

		if (opcaoAlg == 0)
			algoritmo = "BLUBLE SORT";
		else if (opcaoAlg == 1)
			algoritmo = "INSERTION SORT";
		else if (opcaoAlg == 2)
			algoritmo = "SELECTION SORT";
		else
			algoritmo = "QUICK SORT";

		cout << " ESCOLHA A ORDENACAO DESEJADA COM O ALGORITMO " << algoritmo << endl;
		cout << "=========================================================" << endl << endl;

		cout << " Escolha uma opcao para comecar" << endl << endl;

		cout << " 00 - Ordenacao crescente" << endl;
		cout << " 01 - Ordenacao decrescente" << endl;
		cout << " 02 - Ordenacao por pares" << endl;
		cout << " 03 - Ordenacao por impares" << endl;
		cout << " 04 - Ordenacao por primos (se houver)" << endl;
		cout << " 05 - Voltar" << endl << endl;


		cout << " Escolha: ";
		cin >> opcao;
		fflush(stdin);

		cout << endl << endl;
		cout << " Carregando..." << endl;

		Sleep(2000);
		system("cls");

		switch (opcao)
		{

		case 0:
			if (opcaoAlg == 0)
				ordenaBolhaCrescente(vetorSize, vetor);
			else if (opcaoAlg == 1)
				ordenaInsercaoCrescente(vetorSize, vetor);
			else if (opcaoAlg == 2)
				ordenaSelecaoCrescente(vetor, vetorSize);
			else if (opcaoAlg == 3)
			{
				quickSortCrescente(vetor, 0, vetorSize - 1, 0);
				printArray(vetor, vetorSize, 0);
			}

			cout << endl << endl;
			system("pause");break;

		case 1:
			if (opcaoAlg == 0)
				ordenaBolhaDecrescente(vetorSize, vetor);
			else if (opcaoAlg == 1)
				ordenaInsercaoDecrescente(vetorSize, vetor);
			else if (opcaoAlg == 2)
				ordenaSelecaoDecrescente(vetor, vetorSize);
			else if (opcaoAlg == 3)
			{
				quickSortDecrescente(vetor, 0, vetorSize - 1);
				printArray(vetor, vetorSize, 1);
			}

			cout << endl << endl;
			system("pause");break;

		case 2:
			if (opcaoAlg == 0)
				ordenaBolhaPares(vetorSize, vetor);
			else if (opcaoAlg == 1)
				ordenaInsercaoPares(vetorSize, vetor);
			else if (opcaoAlg == 2)
				ordenaSelecaoPares(vetor, vetorSize);
			else if (opcaoAlg == 3)
			{
				quickSortCrescente(vetor, 0, vetorSize - 1, 1);
				printArray(vetor, vetorSize, 2);
			}

			cout << endl << endl;
			system("pause");
			break;

		case 3:
			if (opcaoAlg == 0)
				ordenaBolhaImpares(vetorSize, vetor);
			else if (opcaoAlg == 1)
				ordenaInsercaoImpares(vetorSize, vetor);
			else if (opcaoAlg == 2)
				ordenaSelecaoImpares(vetor, vetorSize);
			else if (opcaoAlg == 3)
			{
				quickSortCrescente(vetor, 0, vetorSize - 1, 2);
				printArray(vetor, vetorSize, 3);
			}


			cout << endl << endl;
			system("pause"); break;
		case 4:
			if (opcaoAlg == 0)
				ordenaBolhaPrimos(vetorSize, vetor);
			else if (opcaoAlg == 1)
				ordenaInsercaoPrimos(vetorSize, vetor);

			cout << endl << endl;
			system("pause"); break;

		default: 
			cout << endl << endl;
			cout << "Escolha uma opcao valida" << endl << endl;
		}

	} while (opcao != 5);
}

void ordenaBolhaCrescente(int vetorSize, int arrayOrdena[])
{
	system("cls");

	cout << " ORDENACAO BOLHA CRESCENTE" << endl << endl;

	int x = 0, y = 0, aux = 0;

	for (x = 0; x < vetorSize; x++)
	{
		for (y = x + 1; y < vetorSize; y++)
		{
			if (arrayOrdena[x] > arrayOrdena[y])
			{
				aux = arrayOrdena[x];
				arrayOrdena[x] = arrayOrdena[y];
				arrayOrdena[y] = aux;
			}
		}
	}


	for (int i = 0; i < vetorSize; i++)
	{
		cout << " Posicao " << i << " : " << arrayOrdena[i] << endl;
	}
}

void ordenaBolhaDecrescente(int vetorSize, int arrayOrdena[])
{
	system("cls");

	cout << " ORDENACAO BOLHA DECRESCENTE" << endl << endl;
	int x = 0, y = 0, aux = 0;

	for (x = 0; x < vetorSize; x++)
	{
		for (y = x + 1; y < vetorSize; y++)
		{
			if (vetor[y] > vetor[x])
			{
				aux = vetor[y];
				vetor[y] = vetor[x];
				vetor[x] = aux;
			}
		}
	}

	for (int i = 0; i < vetorSize; i++)
	{
		cout << " Posição " << i << " : " << arrayOrdena[i] << endl;
	}
}

void ordenaBolhaPares(int vetorSize, int arrayOrdena[])
{
	cout << "ORDENA BOLHA PARES" << endl << endl;
	int x = 0, y = 0, aux = 0;

	for (x = 0; x < vetorSize; x++)
	{
		for (y = x + 1; y < vetorSize; y++)
		{
			if ((arrayOrdena[y] < arrayOrdena[x]) && (arrayOrdena[y] % 2 == 0 && arrayOrdena[x] % 2 == 0))
			{
				aux = arrayOrdena[y];
				arrayOrdena[y] = arrayOrdena[x];
				arrayOrdena[x] = aux;
			}
		}
	}

	for (int i = 0; i < vetorSize; i++)
	{
		if (arrayOrdena[i] % 2 == 1)
			cout << " Posicao " << i << " : " << 1 << endl;
		else
			cout << " Posicao " << i << " : " << arrayOrdena[i] << endl;
	}
}

void ordenaBolhaImpares(int vetorSize, int arrayOrdena[])
{
	cout << "ORDENA BOLHA IMPARES" << endl << endl;
	int x = 0, y = 0, aux = 0;

	for (x = 0; x < vetorSize; x++)
	{
		for (y = x + 1; y < vetorSize; y++)
		{
			if ((arrayOrdena[y] < arrayOrdena[x]) && (arrayOrdena[y] % 2 != 0 && arrayOrdena[x] % 2 != 0))
			{
				aux = arrayOrdena[y];
				arrayOrdena[y] = arrayOrdena[x];
				arrayOrdena[x] = aux;
			}
		}
	}

	for (int i = 0; i < vetorSize; i++)
	{
		if (arrayOrdena[i] % 2 == 0)
			cout << " Posicao " << i << " : " << 2 << endl;
		else
			cout << " Posicao " << i << " : " << arrayOrdena[i] << endl;
	}
}

void ordenaBolhaPrimos(int vetorSize, int arrayOrdena[])
{
	cout << "ORDENACAO BOLHA PRIMOS" << endl << endl;
	int x = 0, y = 0, aux = 0;
	string arrayAux[100];

	for (x = 0; x < vetorSize; x++)
	{
		for (y = x + 1; y < vetorSize; y++)
		{

			int auxP, num1 = arrayOrdena[y], num2 = arrayOrdena[x], div1 = 0, div2 = 0;

			for (auxP = 2; auxP <= arrayOrdena[y] / 2; auxP++)
				if (arrayOrdena[y] % auxP == 0)
					div1++;

			for (auxP = 2; auxP <= arrayOrdena[x] / 2; auxP++)
				if (arrayOrdena[x] % auxP == 0)
					div2++;


			if ((arrayOrdena[y] < arrayOrdena[x]) && (div1 == 0 && div2 == 0))
			{

				aux = arrayOrdena[y];
				arrayOrdena[y] = arrayOrdena[x];
				arrayOrdena[x] = aux;

			}

		}

		int div3 = 0;
		for (int auxP = 2; auxP <= arrayOrdena[x] / 2; auxP++)
			if (arrayOrdena[x] % auxP == 0)
				div3++;

		if (div3 == 0)
			cout << " Posicao " << x << " : " << arrayOrdena[x] << endl;
		else
			cout << " Posicao " << x << " : " << 1 << endl;
	}

}

void ordenaInsercaoCrescente(int vetorSize, int arrayOrdena[])
{
	system("cls");

	cout << " ORDENACAO INSERCAO CRESCENTE" << endl << endl;

	for (int j = 1; j < vetorSize; ++j)
	{
		int x = arrayOrdena[j];
		int i;

		for (i = j - 1; i >= 0 && arrayOrdena[i] > x; --i)
		{
			arrayOrdena[i + 1] = arrayOrdena[i];
		}

		arrayOrdena[i + 1] = x;
	}


	for (int i = 0; i < vetorSize; i++)
	{
		cout << " Posicao " << i << " : " << arrayOrdena[i] << endl;
	}
}

void ordenaInsercaoDecrescente(int vetorSize, int arrayOrdena[])
{
	system("cls");

	cout << " ORDENACAO INSERCAO DECRESCENTE" << endl << endl;

	int i, j, key;

	for (j = 1; j < vetorSize; j++)
	{
		key = arrayOrdena[j];
		for (i = j - 1; (i >= 0) && (arrayOrdena[i] < key); i--)
		{
			arrayOrdena[i + 1] = arrayOrdena[i];
		}
		arrayOrdena[i + 1] = key;
	}


	for (int i = 0; i < vetorSize; i++)
	{
		cout << " Posicao " << i << " : " << arrayOrdena[i] << endl;
	}
}

void ordenaInsercaoPares(int vetorSize, int arrayOrdena[])
{
	system("cls");

	cout << " ORDENACAO INSERCAO PARES" << endl << endl;

	for (int j = 1; j < vetorSize; ++j)
	{
		int x = arrayOrdena[j];
		int i;

		for (i = j - 1; i >= 0 && arrayOrdena[i] > x; --i)
		{
			if (arrayOrdena[i] % 2 == 0)
				arrayOrdena[i + 1] = arrayOrdena[i];
			else
				continue;
		}

		arrayOrdena[i + 1] = x;
	}


	for (int i = 0; i < vetorSize; i++)
	{
		if (arrayOrdena[i] % 2 == 1)
			cout << " Posicao " << i << " : " << 1 << endl;
		else
			cout << " Posicao " << i << " : " << arrayOrdena[i] << endl;
	}
}

void ordenaInsercaoImpares(int vetorSize, int arrayOrdena[])
{
	system("cls");

	cout << " ORDENACAO INSERCAO IMPARES" << endl << endl;

	for (int j = 1; j < vetorSize; ++j)
	{
		int x = arrayOrdena[j];
		int i;

		for (i = j - 1; i >= 0 && arrayOrdena[i] > x; --i)
		{
			if (arrayOrdena[i] % 2 != 0)
				arrayOrdena[i + 1] = arrayOrdena[i];
			else
				continue;
		}

		arrayOrdena[i + 1] = x;
	}


	for (int i = 0; i < vetorSize; i++)
	{
		if (arrayOrdena[i] % 2 == 0)
			cout << " Posicao " << i << " : " << 2 << endl;
		else
			cout << " Posicao " << i << " : " << arrayOrdena[i] << endl;
	}
}

void ordenaInsercaoPrimos(int vetorSize, int arrayOrdena[])
{
	system("cls");

	cout << " ORDENACAO INSERCAO PRIMOS" << endl << endl;

	for (int j = 1; j < vetorSize; ++j)
	{
		int x = arrayOrdena[j];
		int i;


		for (i = j - 1; i >= 0 && arrayOrdena[i] > x; --i)
		{


			arrayOrdena[i + 1] = arrayOrdena[i];
		}

		int div1 = 0;
		for (int auxP = 2; auxP <= x / 2; auxP++)
			if (arrayOrdena[i] % auxP == 0)
				div1++;

		if(div1 == 0)
			arrayOrdena[i + 1] = x;

		
	}


	for (int i = 0; i < vetorSize; i++)
	{
		int div3 = 0;
		for (int auxP = 2; auxP <= arrayOrdena[i] / 2; auxP++)
			if (arrayOrdena[i] % auxP == 0)
				div3++;

		if (div3 == 0)
			cout << " Posicao " << i << " : " << arrayOrdena[i] << endl;
		else
			cout << " Posicao " << i << " : " << 1 << endl;

	}
}

void preencherVetor(int vetorSize)
{
	srand(time(NULL));

	for (int i = 0; i < vetorSize; i++)
	{
		vetor[i] = rand() % 500;
	}

}


void ordenaSelecaoCrescente(int arrayOrdena[], int vetorSize)
{
	cout << "ORDENA SELECAO CRESCENTE" << endl << endl;
	int i, j, min, aux;

	for (i = 0; i < (vetorSize - 1); i++)
	{
		min = i;

		for (j = i + 1; j < vetorSize; j++)
		{
			if (arrayOrdena[j] < arrayOrdena[min])
			{
				min = j;
			}
		}
		if (i != min)
		{
			aux = arrayOrdena[i];
			arrayOrdena[i] = arrayOrdena[min];
			arrayOrdena[min] = aux;
		}
	}

	for (int i = 0; i < vetorSize; i++)
	{
		cout << " Posicao " << i << " : " << arrayOrdena[i] << endl;
	}
}

void ordenaSelecaoDecrescente(int arrayOrdena[], int vetorSize)
{
	cout << "ORDENA SELECAO DECRESCENTE" << endl << endl;
	int i, j, min, aux;

	for (i = 0; i < (vetorSize - 1); i++) {

		min = i;
		for (j = i + 1; j < vetorSize; j++) {

			if (arrayOrdena[j] > arrayOrdena[min]) {
				min = j;
			}
		}

		if (i != min)
		{
			aux = arrayOrdena[i];
			arrayOrdena[i] = arrayOrdena[min];
			arrayOrdena[min] = aux;
		}
	}

	for (int i = 0; i < vetorSize; i++)
	{
		cout << " Posicao " << i << " : " << arrayOrdena[i] << endl;
	}
}

void ordenaSelecaoPares(int arrayOrdena[], int vetorSize)
{
	cout << "ORDENA SELECAO PARES" << endl << endl;
	int i, j, min, aux;

	for (i = 0; i < (vetorSize - 1); i++)
	{
		min = i;

		for (j = i + 1; j < vetorSize; j++)
		{
			if ((arrayOrdena[j] < arrayOrdena[min]) &&
				(arrayOrdena[j] % 2 == 0 && arrayOrdena[min] % 2 == 0))
			{
				min = j;
			}
		}
		if (i != min)
		{
			aux = arrayOrdena[i];
			arrayOrdena[i] = arrayOrdena[min];
			arrayOrdena[min] = aux;
		}
	}

	for (int i = 0; i < vetorSize; i++)
	{
		if (arrayOrdena[i] % 2 == 1)
			cout << " Posicao " << i << " : " << 1 << endl;
		else
			cout << " Posicao " << i << " : " << arrayOrdena[i] << endl;
	}
}

void ordenaSelecaoImpares(int arrayOrdena[], int vetorSize)
{
	cout << "ORDENA SELECAO IMPARES" << endl << endl;
	int i, j, min, aux;

	for (i = 0; i < (vetorSize - 1); i++)
	{
		min = i;

		for (j = i + 1; j < vetorSize; j++)
		{
			if ((arrayOrdena[j] < arrayOrdena[min]) &&
				(arrayOrdena[j] % 2 != 0 && arrayOrdena[min] % 2 != 0))
			{
				min = j;
			}
		}
		if (i != min)
		{
			aux = arrayOrdena[i];
			arrayOrdena[i] = arrayOrdena[min];
			arrayOrdena[min] = aux;
		}
	}

	for (int i = 0; i < vetorSize; i++)
	{
		if (arrayOrdena[i] % 2 == 0)
			cout << " Posicao " << i << " : " << 2 << endl;
		else
			cout << " Posicao " << i << " : " << arrayOrdena[i] << endl;
	}
}
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partitionCrescente(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{

		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

int partitionPares(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{

		if (arr[j] < pivot && arr[j] % 2 == 0)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

int partitionImpares(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{

		if (arr[j] < pivot && arr[j] % 2 != 0)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
int partitionDecrescente(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] > pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSortCrescente(int arr[], int low, int high, int opc)
{

	if (low < high)
	{
		int pi = 0;

		if (opc == 0)
			pi = partitionCrescente(arr, low, high);
		else if (opc == 1)
			pi = partitionPares(arr, low, high);
		else
			pi = partitionImpares(arr, low, high);

		quickSortCrescente(arr, low, pi - 1, opc);
		quickSortCrescente(arr, pi + 1, high, opc);
	}
}

void quickSortDecrescente(int arr[], int low, int high)
{
	if (low < high)
	{

		int pi = partitionDecrescente(arr, low, high);

		quickSortDecrescente(arr, low, pi - 1);
		quickSortDecrescente(arr, pi + 1, high);
	}
}
void printArray(int arr[], int size, int modo)
{
	if (modo == 0)
		cout << "ORDENA QUICKSORT CRESCENTE" << endl << endl;
	else if (modo == 1)
		cout << "ORDENA QUICKSORT DECRESCENTE" << endl << endl;
	else if (modo == 2)
		cout << "ORDENA QUICKSORT PARES" << endl << endl;
	else
		cout << "ORDENA QUICKSORT IMPARES" << endl << endl;

	for (int i = 0; i < size; i++)
	{
		if (modo > 1)
		{
			if (modo == 2 && arr[i] % 2 == 1)
				cout << " Posicao " << i << " : " << 1 << endl;
			else if (modo == 2)
				cout << " Posicao " << i << " : " << arr[i] << endl;

			if (modo == 3 && arr[i] % 2 == 0)
				cout << " Posicao " << i << " : " << 2 << endl;
			else if (modo == 3)
				cout << " Posicao " << i << " : " << arr[i] << endl;
		}
		else
			cout << " Posicao " << i << " : " << arr[i] << endl;
	}

}