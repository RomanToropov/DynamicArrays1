#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);

void Print(int arr[], const int n);

int* push_back(int arr[], int& n);
int* push_front(int arr[], int& n);

int* insert(int arr[], int& n);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);

int* erase(int arr[], int& n);

void main()
{
	cout << int() << endl;
	setlocale(LC_ALL, "ru");
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

}


void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Используя арифметику указателей и оператор разыменования
		*(arr + i) = rand() % 100;
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

//В начале
int* push_back(int arr[], int& n)
{
	int* buffer = new int[n + 1]{};
	int value;
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	cout << "Введите добавляемое значение в начале: "; cin >> value;
	buffer[n] = value;
	delete[] arr;
	arr = buffer;
	n++;
	return arr;
}

//В конце
int* push_front(int arr[], int& n)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	buffer = arr;
	delete[] arr;
	arr = buffer;
	n++;
	return arr;
}

//удаление с конца
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[n - 1]{};
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	cout << "Удаление последнего элемента: " << endl;
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}

// Удаление нулевого
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[n - 1]{};
	for (int i = 1; i < n; i++)
	{
		buffer[i - 1] = arr[i];
	}
	cout << "Удаление нулевого элемента: " << endl;
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}

//Удаление по индексу
int* erase(int arr[], int& n)
{
	int* buffer = new int[n - 1]{};
	int index;
	int h = 0;
	cout << "Введите индекс удаляемого значения : "; cin >> index;
	for (int i = 0; i < n; i++, h++)
	{
		if (i == index - 1)
		{
			i++;
		}
		buffer[h] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}

//Добавление по индексу
int* insert(int arr[], int& n)
{
	int* buffer = new int[n + 1]{};
	int value;
	int index;
	int h = 0;
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите индекс значения: "; cin >> index;
	for (int i = 0; i < n; i++, h++)
	{
		if (i == index - 1)
		{
			buffer[h] = value;
			h++;
		}
		buffer[h] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n++;
	return arr;
}