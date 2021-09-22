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

}


void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//��������� ���������� ���������� � �������� �������������
		*(arr + i) = rand() % 100;
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

//� ������
int* push_back(int arr[], int& n)
{
	int* buffer = new int[n + 1]{};
	int value;
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	cout << "������� ����������� �������� � ������: "; cin >> value;
	buffer[n] = value;
	delete[] arr;
	arr = buffer;
	n++;
	return arr;
}

//� �����
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

//�������� � �����
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[n - 1]{};
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	cout << "�������� ���������� ��������: " << endl;
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}

// �������� ��������
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[n - 1]{};
	for (int i = 1; i < n; i++)
	{
		buffer[i - 1] = arr[i];
	}
	cout << "�������� �������� ��������: " << endl;
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}

//�������� �� �������
int* erase(int arr[], int& n)
{
	int* buffer = new int[n - 1]{};
	int index;
	int h = 0;
	cout << "������� ������ ���������� �������� : "; cin >> index;
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

//���������� �� �������
int* insert(int arr[], int& n)
{
	int* buffer = new int[n + 1]{};
	int value;
	int index;
	int h = 0;
	cout << "������� ����������� ��������: "; cin >> value;
	cout << "������� ������ ��������: "; cin >> index;
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