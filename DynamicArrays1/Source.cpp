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
	int n;//������ �������.
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n] {};

	//���������� � ��������� ������� �����
	FillRand(arr, n);

	Print(arr, n);



	//TODO:
	//�������� �������� � ����� �������.
	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	//1) ������� �������� ������ ������� �������:
	int* buffer = new int[n + 1]{};
	//2) ��������� ��� �������� �� ��������� ������� � ��������:
	//�������� �������� ������ � �������� ��������������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//������� �������� ������:
	delete[] arr;
	//4) ��������� ������ ������ �� �����:
	arr = buffer;
	//5)������ ����� ����� �����, ����� �������� �������� � ����� �������, ��������� � ����� �������,
	//�������� �������, � ������� ����� ��������� ��������:
	arr[n] = value;
	//6) ����� ���������� �������� � ������, ���������� ��� ��������� ������������� �� 1:
	n++;
	Print(arr, n);
	delete[] arr;

#endif // DYNAMIC_MEMORY_1

	int rows; //���������� �����
	int cols; //���������� ��������� ������
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� ������: "; cin >> cols;
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
		//��������� ���������� ���������� � �������� �������������
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
		//��� �� ����� �������� ��������������[]
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