#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

void FillRand(int arr[], const int n, int minRAnd = 0, int MaxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);
int** Push_Row_Back(int** arr,int& rows, const int cols);
int** Push_Row_Front(int** arr, int& rows, const int cols);
int** Insert(int** arr, int& rows, const int cols, int position);	//��������� ������ �� ��������� �������


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
	int position;
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� ������: "; cin >> cols;
	int** arr = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int [cols] {};
	}

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	//arr = Push_Row_Back(arr, rows, cols);
	//FillRand(arr[rows - 1], cols, 200, 1000);
	//Print(arr, rows, cols);
	cout << "\n-----------------------------------------------------\n" << endl;
	arr = Push_Row_Front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "\n-----------------------------------------------------\n" << endl;
	cout << "������ ����������� ������: "; cin >> position;
	arr = Insert(arr, rows, cols, position);
	Print(arr, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

void FillRand(int arr[], const int n, int minRAnd, int MaxRand)
{
	for (int i = 0; i < n; i++)
	{
		//��������� ���������� ���������� � �������� �������������
		*(arr + i) = rand() % (MaxRand - minRAnd)+ minRAnd;
	}
}
void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
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
int** Push_Row_Back(int** arr,int& rows, const int cols)
{
	int** buffer = new int* [rows + 1]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];			//1)dead.
	}
	delete[] arr;
	buffer[rows] = new int[cols] {};		//2)dead.
	rows++;
	return buffer;
}

int** Push_Row_Front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows +1]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	buffer[0] = new int[cols] {};
	++rows;
	return buffer;
}

int** Insert(int** arr, int& rows, const int cols, int position)
{
	int** buffer = new int* [rows +1]{};
	for (int i = 0; i < position; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = position; i < rows; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	buffer[position] = new int[cols] {};
	rows++;
	return buffer;
}