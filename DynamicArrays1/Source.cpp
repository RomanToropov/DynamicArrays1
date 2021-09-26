#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);


//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "ru");
#ifdef DYNAMIC_MEMORY_1
	cout << int() << endl;
	int n;//размер массива.
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {};

	//обращаться к элементам массива можно
	FillRand(arr, n);

	Print(arr, n);



	//TODO:
	//добавить значение в конец массива.
	int value;
	cout << "Введите добовляемое значение: "; cin >> value;
	//1) Создаем буферный массив нужного размера:
	int* buffer = new int[n + 1]{};
	//2) Перенести все значения из исходного массива в буферный:
	//копируем исходный массив в буферный СООТВЕТСТВЕННО:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//Удаляем исходный массив:
	delete[] arr;
	//4) Подменяем старый массив на новый:
	arr = buffer;
	//5)Только после всего этого, можно добавить значение в конце массива, поскольку в конце массива,
	//появился элемент, в который можно сохранить значение:
	arr[n] = value;
	//6) После добавления элемента в массив, количество его элементов увеличивается на 1:
	n++;
	Print(arr, n);
	delete[] arr;

#endif // DYNAMIC_MEMORY_1

	int rows; //количество строк
	int cols; //количество элементов строки
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	int** arr = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int [cols] {};
	}

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Используя арифметику указателей и оператор разыменования
		*(arr + i) = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//или же через оператор индексирования[]
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}