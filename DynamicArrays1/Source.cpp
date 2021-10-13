//DynamicArrays
#include<iostream>
using namespace std;
using std::cout;
using std::cin;

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);

int* Push_Back(int arr[], int& n, int value);
int** Push_Row_Back(int** arr, int& rows, const int cols, int stroka[]);
int** Push_Col_Back(int** arr, const int rows, int& cols, int stroka[]);
void Push_Col_Back(int** arr, const int rows, int& cols); // � ������


int* Push_Front(int arr[], int& n, int value);
int** Push_Row_Front(int** arr, int& rows, const int cols, int stroka[]);
int** Push_Col_Front(int** arr, const int rows, int& cols, int stroka[]);

int* Pop_Back(int arr[], int& n);
int** Pop_Row_Back(int** arr, int& rows, const int cols);
int** Pop_Col_Back(int** arr, const int rows, int& cols);
void Pop_col_Back(int** arr, const int rows, int& cols); // � ������ (������ �����)

int* Pop_Front(int arr[], int& n);
int** Pop_Row_Front(int** arr, int& rows, const int cols);
int** Pop_Col_Front(int** arr, const int rows, int& cols);


int* Insert(int arr[], int& n, int value, int index_value);
int** Insert_Row(int** arr, int& rows, const int cols, int stroka[], int index);
int** Insert_Col(int** arr, const int rows, int& cols, int stroka[], int index);


int* Erase(int arr[], int& n, int value, int index_value);
int** Erase_Row(int** arr, int& rows, const int cols, int index);
int** Erase_Col(int** arr, const int rows, int& cols, int index);


//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	//cout << int() << endl; // ������� �������� �� ��������� ��� ���� ������ 'int'
	setlocale(LC_ALL, "Russian");
#ifdef DYNAMIC_MEMORY_1
	int n; // ������ �������
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n] {}; //Heap

	//���������� � ��������� ������� �����
	FillRand(arr, n);
	Print(arr, n);
	cout << endl;

	int value;
	int index_value;
	cout << "������� ����������� �������� � ������: "; cin >> value;
	cout << "������� ������ ������������/���������� �������� (�� 0 �� " << n - 1 << "): "; cin >> index_value;

	//TODO:
	//�������� �������� � ����� �������
#ifdef ONE
	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	//1) ������ �������� ������ ������� �������:
	int* buffer = new int[n + 1]{};
	//2) ��������� ��� �������� �� ��������� ������� � ��������.
	//�������� �������� ������ � �������� ��������������
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������:
	delete[] arr;
	//4) ��������� ������ ������ �� �����
	arr = buffer;
	//5) ������ ����� ����� �����, ����� �������� �������� � ����� �������,
	// ��������� � ����� ������� �������� �������, � ������� ����� ��������� ��������:
	arr[n] = value;
	//6) ����� ���������� �������� � ������, ���������� ��� ��������� ������������� �� 1:
	n++;
#endif ONE

	arr = Erase(arr, n, value, index_value);
	Print(arr, n);

	delete[] arr;

#endif DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int rows; // ���������� �����
	int cols; // ���������� ��������� ������
	cout << "������� ��������� ����� (rows): "; cin >> rows;
	cout << "������� ��������� ��������� ������ (cols): "; cin >> cols;

	int** arr = Allocate(rows, cols);
	int** arr = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	cout << "������ ������, ������ ����� ��������� ������";
	cout << endl;
	//system("PAUSE");
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << endl;

	int index;
	int* stroka = new int[cols] {147};
	cout << "����������� ������ (�������): " << endl << endl;
	Print(stroka, cols);
	cout << endl << endl;
	cout << "������� ������ ����������� (���������) ������ (�������), �� 0 �� " << rows << " (�� 0 �� " << cols << "): "; cin >> index;
	cout << endl << endl;

	arr = Push_Row_Back(arr, rows, cols, stroka);
	arr = Push_Col_Back(arr, rows, cols, stroka);

	arr = Push_Row_Front(arr, rows, cols, stroka);
	arr = Push_Col_Front(arr, rows, cols, stroka);

	arr = Pop_Row_Back(arr, rows, cols);
	arr = Pop_Col_Back(arr, rows, cols);

	arr = Pop_Row_Front(arr, rows, cols);
	arr = Pop_Col_Front(arr, rows, cols);

	arr = Insert_Row(arr, rows, cols, stroka, index);
	arr = Insert_Col(arr, rows, cols, stroka, index);

	arr = Erase_Row(arr, rows, cols, index);
	arr = Erase_Col(arr, rows, cols, index);

	cout << "������ ���������" << endl;
	FillRand(arr[rows - 1], cols, 200, 1000);

	Push_Col_Back(arr, rows, cols);
	Pop_col_Back(arr, rows, cols);

	Print(arr, rows, cols);
	cout << endl;

	
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

	Clear(arr, rows);

#endif DYNAMIC_MEMORY_2
}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		//��������� ���������� ���������� � �������� �������������:
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
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
		//��� �� ����� �������� ��������������[]:
		cout << arr[i] << "\t";
	}
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

int** Allocate(int const rows, int const cols)
{
	int** arr = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}

void Clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

int* Push_Back(int arr[], int& n, int value)
{
	cout << "������� �������� � ����� �������: " << endl;
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
	return arr;
}

int** Push_Row_Back(int** arr, int& rows, const int cols, int stroka[])
{
	cout << "������� ������ � ����� �������: " << endl << endl;
	int** buffer = new int* [rows + 1]{};

	buffer[rows] = stroka;

	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr;

	arr = buffer;

	rows++;
	return arr;
}

int** Push_Col_Back(int** arr, const int rows, int& cols, int stroka[])
{
	cout << "������� ������� � ����� �������: " << endl << endl;
	int** buffer = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols + 1]{};
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		delete[] arr[i];
	}

	for (int i = 0; i < rows; i++)
	{
		buffer[i][cols] = stroka[i];
	}

	delete[] arr;

	arr = buffer;

	cols++;
	return arr;
}

void Push_Col_Back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

int* Push_Front(int arr[], int& n, int value)
{
	cout << "������� �������� � ������ �������: " << endl;
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}

int** Push_Row_Front(int** arr, int& rows, const int cols, int stroka[])
{
	cout << "������� ������ � ������ �������: " << endl << endl;
	int** buffer = new int* [rows + 1]{};

	buffer[0] = stroka;

	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}

	delete[] arr;

	arr = buffer;

	rows++;
	return arr;
}

int** Push_Col_Front(int** arr, const int rows, int& cols, int stroka[])
{
	cout << "������� ������� � ������ �������: " << endl << endl;
	int** buffer = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols + 1]{};
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j + 1] = arr[i][j];
		}
		delete[] arr[i];
	}

	for (int i = 0; i < rows; i++)
	{
		buffer[i][0] = stroka[i];
	}

	delete[] arr;

	arr = buffer;

	cols++;
	return arr;
}

int* Pop_Back(int arr[], int& n)
{
	cout << "������ ��������� ������� �������: " << endl;
	int* buffer = new int[n - 1]{};
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}

int** Pop_Row_Back(int** arr, int& rows, const int cols)
{
	cout << "������ ������ � ����� �������: " << endl << endl;
	int** buffer = new int* [rows - 1]{};

	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr[rows - 1];
	delete[] arr;

	arr = buffer;

	rows--;
	return arr;
}

int** Pop_Col_Back(int** arr, const int rows, int& cols)
{
	cout << "������ ������ � ����� �������: " << endl << endl;
	int** buffer = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols - 1]{};
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		delete[] arr[i];
	}

	delete[] arr;

	arr = buffer;

	cols--;
	return arr;
}

void Pop_col_Back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}

int* Pop_Front(int arr[], int& n)
{
	cout << "������ ������ ������� �������: " << endl;
	int* buffer = new int[n - 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}

int** Pop_Row_Front(int** arr, int& rows, const int cols)
{
	cout << "������ ������ � ������ �������: " << endl << endl;
	int** buffer = new int* [rows - 1]{};

	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i + 1];
	}

	delete[] arr[0];
	delete[] arr;

	arr = buffer;

	rows--;
	return arr;
}

int** Pop_Col_Front(int** arr, const int rows, int& cols)
{
	cout << "������ ������ � ������ �������: " << endl << endl;
	int** buffer = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols - 1]{};
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[i][j] = arr[i][j + 1];
		}
		delete[] arr[i];
	}

	delete[] arr;

	arr = buffer;

	cols--;
	return arr;
}

int* Insert(int arr[], int& n, int value, int index_value)
{
	cout << "������� �������� �� ���������� �������: " << endl;
	int* buffer = new int[n + 1]{};
	for (int i = 0; i <= index_value; i++)
	{
		i != index_value ? buffer[i] = arr[i] : buffer[i] = value;
	}

	for (int i = index_value; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n++;
	return arr;
}

int** Insert_Row(int** arr, int& rows, const int cols, int stroka[], int index)
{
	if (index > rows) return arr;
	cout << "������� ������ � ������ �� �������: " << index << endl << endl;
	int** buffer = new int* [rows + 1]{};

	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}

	buffer[index] = stroka;

	for (int i = index; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows++;
	return arr;
}

int** Insert_Col(int** arr, const int rows, int& cols, int stroka[], int index)
{
	if (index > cols) return arr;
	cout << "������� ������� � ������ �� �������: " << index << endl << endl;
	int** buffer = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols + 1]{};
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < index; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		for (int j = index; j < cols; j++)
		{
			buffer[i][j + 1] = arr[i][j];
		}
		delete[] arr[i];
	}

	for (int i = 0; i < rows; i++)
	{
		buffer[i][index] = stroka[i];
	}

	delete[] arr;

	arr = buffer;
	cols++;
	return arr;
}

int* Erase(int arr[], int& n, int value, int index_value)
{
	cout << "������ �������� �� ���������� �������: " << endl;
	int* buffer = new int[n - 1]{};
	for (int i = 0; i < index_value; i++)
	{
		buffer[i] = arr[i];
	}

	for (int i = index_value; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}

int** Erase_Row(int** arr, int& rows, const int cols, int index)
{
	if (index >= rows) return arr;
	cout << "������ ������ �� ������� �� �������: " << index << endl << endl;
	int** buffer = new int* [rows - 1]{};

	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}

	for (int i = index; i < rows; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}

int** Erase_Col(int** arr, const int rows, int& cols, int index)
{
	if (index > cols) return arr;
	cout << "������ ������� �� ������� �� �������: " << index << endl << endl;
	int** buffer = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols - 1]{};
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < index; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		for (int j = index; j < cols; j++)
		{
			buffer[i][j] = arr[i][j + 1];
		}
		delete[] arr[i];
	}

	delete[] arr;

	arr = buffer;
	cols--;
	return arr;
}