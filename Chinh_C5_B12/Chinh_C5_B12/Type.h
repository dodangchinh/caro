#pragma once
const int column = 7;

void DrawBorder(int n);
void InputNumber(int &n, char c[]);
void Inputpos(int n, int &row, char c[]);
void Input(int arr[], int n, char c);
void Input(int &n, char c[]);
void InputValue(int &n);
void Inputposition(int n, int &pos);

void Output(int arr[], int n, char c);
int isOdd(int n);
int isPrime(int n);
void InsertAt(int arr[], int &n, int value, int pos);
void Delete(int arr[], int &n, int pos);
void InitializeValuesArray(int arr[], int &n, int value);
int isExist(int arr[], int n, int value);
void Swap(int &a, int &b);
void InterChange(int arr[], int n);
void SelectionSort(int arr[], int n);
void BubbleSort(int arr[], int n);
void Insert(int arr[], int pos, int value);
void InsertionSort(int arr[], int n);
void Input2D(int arr[][column], int row, int column);
void Output2D(int arr[][column], int row, int column);
void InputRandom(int a[][column], int &dong, int &cot);
void SelectInput(int arr2D[][column], int &row, int &column, int flag);
void SET_COLOR(int color);

void getUpDown(int arr2D[][column], int row, int posR, int posC, int Value, int &Up, int &Down);
void getLeftRight(int arr2D[][column], int column, int posR, int posC, int Value, int &Left, int &Right);
void getDiagonalUpDown(int arr2D[][column], int row, int column, int posR, int posC, int Value, int &DiagonalUp, int &DiagonalDown);
void getSecondDiagonalUpDown(int arr2D[][column], int row, int column, int posR, int posC, int Value, int &SecondDiagonallUp, int &SecondDiagonalDown);