#include "stdafx.h"
#include "stdio.h"
#include "cmath"
#include "math.h"
#include "windows.h"
#include "time.h"

const int rows = 7;
const int columns = 7;
const int Max = 20;
const int length = 50;

void DrawBorder(int n)
{
	printf("\n");
	for (int i = 1; i < n; i++)
		printf("=");
	printf("\n");
}

void InputNumber(int &n, char c[])
{
	do
	{
		printf("Number %s: ", c);
		scanf_s("%d", &n);
		DrawBorder(length);
	} while (n < 1 || n > Max);
}

void Inputpos(int n, int &row, char c[])
{
	do
	{
		printf("pos Number %s: ", c);
		scanf_s("%d", &row);
		row--;
		DrawBorder(length);
	} while (row < 0 || row > n);
}


void Input(int arr[], int n, char c)
{
	for (int i = 0; i < n; i++)
	{
		printf("arr%c[%d]: ", c, i);
		scanf_s("%d", &arr[i]);
	}
	DrawBorder(length);
}

void InputValue(int &n)
{
	printf("Value:");
	scanf_s("%d", &n);
}

void Inputposition(int n, int &pos)
{
	do {
		printf("position:");
		scanf_s("%d", &pos);
	} while (pos < 0 || pos > n);
	pos = pos - 1;
}

void Input(int &n, char c[])
{
	printf("Number %s: ", c);
	scanf_s("%d", &n);
	DrawBorder(length);
	if (n < 5)
		do
		{
			printf("Number %s (Number > 5): ", c);
			scanf_s("%d", &n);
			DrawBorder(length);
		} while (n < 5 || n > Max);
}

void Output(int arr[], int n, char c)
{
	printf("Arr%c = [", c);
	for (int i = 0; i < n; i++)
	{
		printf("%d", arr[i]);
		if (i == n - 1)
			printf("]");
		else
			printf("\t");
	}
}

int isOdd(int n)
{
	if (n % 2 != 0)
		return 1;
	return 0;
}

int isPrime(int n)
{
	if (n < 2)
		return 0;
	else
		for (int idx = 2; idx < sqrt(n); idx++)
			if (n % idx == 0)
				return 0;
	return 1;
}

// thêm phần tử value tại vị trí pos trong mảng a
void InsertAt(int arr[], int &n, int value, int pos)
{
	// arr: 1 2 3
	// value: 100, pos = 1
	// arr[3] = arr[2] = 3
	// arr[2] = arr[1] = 2

	// arr[pos] = value
	// 1 100 2 3 --> n = 4
	for (int i = n - 1; i >= pos; i--)
		arr[i + 1] = arr[i];
	n++;
	arr[pos] = value;
}

// xóa phần tử trong mảng a tại vị trí pos
void Delete(int arr[], int &n, int pos)
{
	for (int i = pos; i < n; i++)
	{
		arr[i] = arr[i + 1];
	}
	n--;
}

void InitializeValuesArray(int arr[], int &n, int value)
{
	arr[n] = value;
	n++;
}

int isExist(int arr[], int n, int value)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == value)
			return 1;
	}
	return 0;
}

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void InterChange(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
				Swap(arr[i], arr[j]);
		}
		Output(arr, n, 'A');
	}
}

void SelectionSort(int arr[], int n)
{
	int posMin; // vị trí của phần tử nhỏ nhất(trong phần chưa sắp)
	for (int i = 0; i < n - 1; i++)
	{
		// tìm phần tử nhỏ nhất trong phần chưa sắp
		posMin = i;

		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[posMin])
				//ghi nhận lại vị trí
				posMin = j;
		}
		// Swap element min được tìm thấy với phần tử đầu.
		Swap(arr[posMin], arr[i]);
	}
}

void BubbleSort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (arr[j] < arr[j - 1])
				Swap(arr[j], arr[j - 1]);
		}
	}
}

void Insert(int arr[], int pos, int value)
{
	while (arr[pos] > value)
	{
		arr[pos + 1] = arr[pos];
		pos--;
	}
	arr[pos + 1] = value;
}


void InsertionSort(int arr[], int n)
{
	int pos;
	// lưu giá trị a[i] tránh bị ghi đè khi dời chổ các phần tử  
	int value;

	for (int i = 1; i < n; i++)
	{
		value = arr[i];
		pos = i - 1;
		Insert(arr, pos, value);
	}
}

// Tìm kiếm nhị phân
int SearchBinary(int a[], int n, int value)
{
	int left = 0;
	int right = n - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;

		if (a[mid] == value)
			return mid;
		else if (a[mid] > value)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}

// 2 mảng
void Input2D(int arr[][columns], int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			printf("a[%d][%d]: ", i, j);
			scanf_s("%d", &arr[i][j]);
		}
	}
}

void Output2D(int arr[][columns], int row, int column)
{
	DrawBorder(length);
	if (row == column)
		printf("Block Square:\n");

	else
		printf("Block Rectangle:\n");
	printf("\t");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
			printf("\t%d", arr[i][j]);
		printf("\n\n\n");
		printf("\t");
	}
	printf("\n");
}

void InputRandom(int a[][columns], int &dong, int &cot)
{
	// Nhập biến dong và biến cot như bình thường
	srand((unsigned int)time(0));
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			// (rand() % [b – a + 1]) + a
			a[i][j] = (rand() % 601) + 0;
		}
	}
}

// trường hợp đặc biệt: matrix square
// for (int i = 0; i < dong * cot; i++) 
// {
//		// a[i/cot][i%cot]
// }

void SelectInput(int arr2D[][columns], int &row, int &column, int flag)
{
	do
	{
		printf("Select the input method:\n");
		printf("1. Free input!");
		printf("\n");
		printf("2. Random input!");
		DrawBorder(length);

		scanf_s("%d", &flag);

	} while (flag > 2 || flag < 1);

	if (flag == 1)
		Input2D(arr2D, row, column);
	DrawBorder(length);
	if (flag == 2)
		InputRandom(arr2D, row, column);
	DrawBorder(length);
}

void SET_COLOR(int color)
{
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}

void getUpDown(int arr2D[][columns], int row, int posR, int posC, int Value, int &Up, int &Down)
{
	if (posR - 1 >= 0)
		Up = arr2D[posR - 1][posC];
	else
		Up = Value;

	if (posR < row - 1)
		Down = arr2D[posR + 1][posC];
	else
		Down = Value;
}

void getLeftRight(int arr2D[][columns], int column, int posR, int posC, int Value, int &Left, int &Right)
{
	if (posC - 1 >= 0)
		Left = arr2D[posR][posC - 1];
	else
		Left = Value;

	if (posC < column)
		Right = arr2D[posR][posC + 1];
	else
		Right = Value;
}

void getDiagonalUpDown(int arr2D[][columns], int row, int column, int posR, int posC, int Value, int &DiagonalUp, int &DiagonalDown)
{
	if (posR - 1 >= 0 && posC - 1 >= 0)
		DiagonalUp = arr2D[posR - 1][posC - 1];
	else
		DiagonalUp = Value;

	if (posR + 1 < row && posC + 1 < row)
		DiagonalDown = arr2D[posR + 1][posC + 1];
	else
		DiagonalDown = Value;
}

void getSecondDiagonalUpDown(int arr2D[][columns], int row, int column, int posR, int posC, int Value, int &SecondDiagonallUp, int &SecondDiagonalDown)
{
	if (posR - 1 >= 0 && posC + 1 >= 0 && posC + 1 <= row)
		SecondDiagonallUp = arr2D[posR - 1][posC + 1];
	else
		SecondDiagonallUp = Value;

	if (posR + 1 < row && posC - 1 < row && posC - 1 >= 0)
		SecondDiagonalDown = arr2D[posR + 1][posC - 1];
	else
		SecondDiagonalDown = Value;
}