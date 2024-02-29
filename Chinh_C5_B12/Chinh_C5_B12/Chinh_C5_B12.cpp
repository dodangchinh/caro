// Chinh_C5_B11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include "math.h"
#include "windows.h"
#include "time.h"
#include "Type.h"

const int Max = 20;
const int rows = 7;
const int columns = 7;
const int length = 50;

void setColorXO(char c)
{
	if (c == 'O')
		SET_COLOR(12);
	if (c == 'X')
		SET_COLOR(14);
}

void Draw(char c)
{
	printf("%c", c);
}

void DrawRowAndLowerRightCorner(int n)
{
	n = (n * 8) + 7;
	for (int i = 1; i < n; i++)
		Draw(205);
	SET_COLOR(9);
	Draw(188);
}

void DrawUppeLeftCornerAndNumberRow(int n)
{
	if (n == -1)
	{
		SET_COLOR(9);
		Draw(201);
	}
	else
	{
		printf("%d", n + 1);
		SET_COLOR(15);
	}
}

void DrawColumn(int row, int n)
{
	if (row == n - 1)
	{
		printf("\t");
		Draw(186);
	}
}

void DrawColumnInRowWithoutBlock(int n)
{
	n = (n * 8) + 9;
	for (int i = 1; i < n; i++)
		Draw(32);
	Draw(186);
}

void DrawLowerLeftCornerAndColumn(int n)
{
	SET_COLOR(9);
	Draw(200);
	SET_COLOR(15);
	Draw(205);
	DrawRowAndLowerRightCorner(n);
	printf("\n");
}

void DrawUpperRightCornerAndNumberColumn(int n, int row)
{
	if (row == -1)
	{
		for (int idxA = 0; idxA < n; idxA++)
			printf("\t%d", idxA + 1);

		SET_COLOR(9);
		printf("\t");
		Draw(187);
		SET_COLOR(15);
	}
}

void OutputColumnInRowWithoutBlock(int n)
{
	printf("\n");
	DrawColumnInRowWithoutBlock(n);
	printf("\n");
	DrawColumnInRowWithoutBlock(n);
	printf("\n");
	DrawColumnInRowWithoutBlock(n);
	printf("\n");
}

void OutputChar2D(char arr2D[][columns], int n)
{
	char c;
	for (int idxA = -1; idxA < n; idxA++)
	{
		DrawUppeLeftCornerAndNumberRow(idxA);
		SET_COLOR(15);
		if (idxA == -1)
			DrawUpperRightCornerAndNumberColumn(n, idxA);
		else
			for (int idxB = 0; idxB < n; idxB++)		
			{
				c = arr2D[idxA][idxB];

				setColorXO(c);
				printf("\t%c", arr2D[idxA][idxB]);

				SET_COLOR(15);
				DrawColumn(idxB, n);
			}
		OutputColumnInRowWithoutBlock(n);
	}
	DrawLowerLeftCornerAndColumn(n);
}

void ClearAndOutput(char arr2D[][columns], int n)
{
	system("cls");
	OutputChar2D(arr2D, n);
}

void InitBoard(char arr2D[][columns], int n)
{
	for (int idxA = 0; idxA < n; idxA++)
		for (int idxB = 0; idxB < n; idxB++)
			arr2D[idxA][idxB] = '_';
}

void InputPlayer(char c, int n, int &posR, int &posC)
{
	setColorXO(c);

	printf("Player %c:\n", c);

	printf("Input Row: ");
	scanf_s("%d", &posR);

	printf("Input Column: ");
	scanf_s("%d", &posC);

	posR -= 1;
	posC -= 1;
}

int isCheck(char arr2D[][columns], int n, int posR, int posC)
{
	if (posR > n - 1 || posR < 0
		|| posC > n - 1 || posC < 0)
		return 0;
	return 1;
}

int isExist(char arr2D[][columns], int n, int posR, int posC, char c)
{
	if (arr2D[posR][posC] == 'O'
		|| arr2D[posR][posC] == 'X')
		return 0;
	return 1;
}

void CheckAndExist(char arr2D[][columns], int n, int &posR, int &posC, char c)
{
	int Check = -1;
	int Exist = -1;

	while (isCheck(arr2D, n, posR, posC) == 0 
		|| isExist(arr2D, n, posR, posC, c) == 0)
	{
		Check = isCheck(arr2D, n, posR, posC);
		Exist = isExist(arr2D, n, posR, posC, c);
		
		if (Check == 0)
		{
			ClearAndOutput(arr2D, n);

			SET_COLOR(15);
			printf("Wrong input position. Input again!\n");
			InputPlayer(c, n, posR, posC);

			ClearAndOutput(arr2D, n);
		}

		if (Exist == 0)
		{
			ClearAndOutput(arr2D, n);

			SET_COLOR(15);
			printf("This position has been marked already. Input again!\n");
			InputPlayer(c, n, posR, posC);

			ClearAndOutput(arr2D, n);
		}
	}
}

void OutputStep(int n, int posR, int posC, char c)
{
	setColorXO(c);

	DrawBorder((n * 8) + 10);
	printf("Player (%c) go to step [%d][%d]!", c, posR + 1, posC + 1);
	DrawBorder((n * 8) + 10);
}

void InputOX(char arr2D[][columns], int n, int &posR, int &posC, char c)
{
	SET_COLOR(15);
	InputPlayer(c, n, posR, posC);
	CheckAndExist(arr2D, n, posR, posC, c);

	arr2D[posR][posC] = c;

	ClearAndOutput(arr2D, n);
	OutputStep(n, posR, posC, c);
}

int isOutofbound(int n, int m)
{
	if (n > m)
		return 1;
	if (n < m)
		return 1;
	if (n >= m)
		return 1;
	if (n <= m)
		return 1;
	return 0;
}

void getValue(char arr2D[][column], int posR, int posC, char &Variable)
{
	Variable = arr2D[posR][posC];
}

void getValueV2(char &Variable)
{
	Variable = '_';
}

void getUp(char arr2D[][column], int posR, int posC, char &Up)
{
	if (isOutofbound(posR, 0))
		getValue(arr2D, posR, posC, Up);
	else
		getValueV2(Up);
}

void getDown(char arr2D[][column], int n, int posR, int posC, char &Down)
{
	if (isOutofbound(posR, n - 1))
		getValue(arr2D, posR, posC, Down);
	else
		getValueV2(Down);
}

void getLeft(char arr2D[][column], int posR, int posC, char &Left)
{
	if (isOutofbound(posC, 0))
		getValue(arr2D, posR, posC, Left);
	else
		getValueV2(Left);
}

void getRight(char arr2D[][column], int n, int posR, int posC, char &Right)
{
	if (isOutofbound(posC, n))
		getValue(arr2D, posR, posC, Right);
	else
		getValueV2(Right);
}

void getDiagonalUp(char arr2D[][column], int posR, int posC, char &DiagonalUp)
{
	if (isOutofbound(posR, 0) && isOutofbound(posC, 0))
		getValue(arr2D, posR, posC, DiagonalUp);
	else
		getValueV2(DiagonalUp);
}

void getDiagonalDown(char arr2D[][column], int n, int posR, int posC, char &DiagonalDown)
{
	if (isOutofbound(posR, n) && isOutofbound(posC, n))
		getValue(arr2D, posR, posC, DiagonalDown);
	else
		getValueV2(DiagonalDown);
}

void getSecondDiagonalUp(char arr2D[][column], int n, int posR, int posC, char &SecondDiagonallUp)
{
	if (isOutofbound(posR, 0) 
		&& isOutofbound(posC, 0) && isOutofbound(posC, n))
		getValue(arr2D, posR, posC, SecondDiagonallUp);
	else
		getValueV2(SecondDiagonallUp);
}

void getSecondDiagonalDown(char arr2D[][column], int n, int posR, int posC, char &SecondDiagonalDown)
{
	if (isOutofbound(posR, n) 
		&& isOutofbound(posC, n) && isOutofbound(posC, 0))
		getValue(arr2D, posR, posC, SecondDiagonalDown);
	else
		getValueV2(SecondDiagonalDown);
}

void OutputWin(char arr2D[][columns], int n, char c)
{
	ClearAndOutput(arr2D, n);
	setColorXO(c);

	printf("\n");
	printf("Player (%c) win!", c);
}

int isOutofboundV2(int posR, int posC)
{
	if (posR >= 0 && posC >= 0)
		return 1;
	return 0;
}

int isUpDown(char arr2D[][columns], int n, int posR, int posC, char c)
{
	int count = 0;
	char Up;
	char Down;

	getUp(arr2D, posR, posC, Up);
	
	while (Up == c && isOutofboundV2(posR, posC))
	{
		posR -= 1;
		getUp(arr2D, posR, posC, Up);
		count++;
	}

	posR += (count + 1);

	getDown(arr2D, n, posR, posC, Down);	
	while (Down == c && isOutofboundV2(posR, posC))
	{
		posR += 1;
		getDown(arr2D, n, posR, posC, Down);
		count++;
	}

	if (count == 5)
		return 1;
	return 0;
}

int isLeftRight(char arr2D[][columns], int n, int posR, int posC, char c)
{
	int count = 0;
	char Left;
	char Right;

	getLeft(arr2D, posR, posC, Left);
	while (Left == c 
		&& isOutofboundV2(posR, posC))
	{
		posC -= 1;
		getLeft(arr2D, posR, posC, Left);
		count++;
	}

	posC += (count + 1);

	getRight(arr2D, n, posR, posC, Right);
	while (Right == c 
		&& isOutofboundV2(posR, posC))
	{
		posC += 1;
		getDown(arr2D, n, posR, posC, Right);
		count++;
	}

	if (count == 5)
		return 1;
	return 0;
}

int isDiagonal(char arr2D[][columns], int n, int posR, int posC, char c)
{
	int count = 0;
	char DiagonalUp;
	char DiagonalDown;

	getDiagonalUp(arr2D, posR, posC, DiagonalUp);
	while (DiagonalUp == c
		&& isOutofboundV2(posR, posC))
	{
		posR -= 1;
		posC -= 1;

		getDiagonalUp(arr2D, posR, posC, DiagonalUp);
		count++;
	}

	posR += (count + 1);
	posC += (count + 1);

	getDiagonalDown(arr2D, n, posR, posC, DiagonalDown);
	while (DiagonalDown == c
		&& isOutofboundV2(posR, posC))
	{
		posR += 1;
		posC += 1;

		getDiagonalUp(arr2D, posR, posC, DiagonalDown);
		count++;
	}

	if (count == 5)
		return 1;
	return 0;
}

int isSecondDiagonal(char arr2D[][columns], int  n, int posR, int posC, char c)
{
	int count = 0;
	char SecondDiagonallUp;
	char SecondDiagonalDown;

	getSecondDiagonalUp(arr2D, n, posR, posC, SecondDiagonallUp);
	while (SecondDiagonallUp == c
		&& isOutofboundV2(posR, posC))
	{
		posR -= 1;
		posC += 1;

		getSecondDiagonalUp(arr2D, n, posR, posC, SecondDiagonallUp);
		count++;
	}

	posR += (count + 1);
	posC -= (count + 1);

	getSecondDiagonalDown(arr2D, n, posR, posC, SecondDiagonalDown);
	while (SecondDiagonalDown == c 
		&& isOutofboundV2(posR, posC))
	{
		posR += 1;
		posC -= 1;

		getSecondDiagonalUp(arr2D, n, posR, posC, SecondDiagonalDown);
		count++;
	}

	if (count == 5)
		return 1;
	return 0;
}

int CheckWin(char arr2D[][columns], int n, int &posR, int &posC, char c)
{
	if (isUpDown(arr2D, n, posR, posC, c)
		|| isLeftRight(arr2D, n, posR, posC, c)
		|| isDiagonal(arr2D, n, posR, posC, c)
		|| isSecondDiagonal(arr2D, n, posR, posC, c))
	{
		OutputWin(arr2D, n, c);
		return 1;
	}
		
	return 0;
}

int SelectPlayer(char arr2D[][columns], int n, char &char1, char &char2)
{
	char flag;
	do
	{
		printf("Select X or O:\n");
		printf("Player 1: ");
		scanf_s(" %c", &flag);
		printf("\n");
		DrawBorder((n * 8) + 10);
	} while (flag != 'X' && flag != 'O');

	ClearAndOutput(arr2D, n);

	if (flag == 'O')
	{
		char1 = 'O';
		char2 = 'X';
		return 1;
	}
	else
	{
		char1 = 'X';
		char2 = 'O';
		return 0;
	}
}

void Player(char arr2D[][columns], int n, int &posR, int &posC, char c)
{
	char char1;
	char char2;

	SelectPlayer(arr2D, n, char1, char2);

	while (1)
	{
		InputOX(arr2D, n, posR, posC, char1);
		if (CheckWin(arr2D, n, posR, posC, char1))
			break;

		InputOX(arr2D, n, posR, posC, char2);
		if (CheckWin(arr2D, n, posR, posC, char2))
			break;	
	}
}

void InputComputer(char arr2D[][columns], int n, int &posR, int &posC, char char1, char char2)
{
	setColorXO(char2);

	printf("Player %c:\n", char2);

	while (arr2D[posR][posC] == char1
		|| arr2D[posR][posC] == char2)
	{
		srand((unsigned int)time(0));
		posR = (rand() % n - 1 + 1) + 1;
		posC = (rand() % n - 1 + 1) + 1;

		posR -= 1;
		posC -= 1;
	}
}

void InputOXComputer(char arr2D[][columns], int n, int &posR, int &posC, char char1, char char2)
{
	SET_COLOR(15);
	InputComputer(arr2D, n, posR, posC, char1, char2);
	CheckAndExist(arr2D, n, posR, posC, char2);

	arr2D[posR][posC] = char2;

	ClearAndOutput(arr2D, n);
}

void PlayerVsComputer(char arr2D[][columns], int n, int &posR, int &posC, char c)
{
	char char1;
	char char2;

	SelectPlayer(arr2D, n, char1, char2);

	while (1)
	{
		InputOX(arr2D, n, posR, posC, char1);
		if (CheckWin(arr2D, n, posR, posC, char1))
			break;

		InputOXComputer(arr2D, n, posR, posC, char1, char2);
		if (CheckWin(arr2D, n, posR, posC, char2))
			break;
		OutputStep(n, posR, posC, char2);
		
	}
}

void OutputResult(char arr2D[][columns], int n, int flag, int posR, int posC, char c)
{
	system("cls");
	InitBoard(arr2D, n);

	if (flag == 1)
		Player(arr2D, n, posR, posC, c);
	else
		PlayerVsComputer(arr2D, n, posR, posC, c);
}

void Select(char arr2D[][columns], int &n, int posR, int posC, int flag)
{
	do
	{
		printf("Select game mode:\n");
		printf("1. Player vs Player!");
		printf("\n");
		printf("2. Player vs Computer!");
		DrawBorder((n * 8) + 10);

		scanf_s("%d", &flag);

	} while (flag != 1 && flag != 2);

    OutputResult(arr2D, n, flag, posR, posC, ' ');
	DrawBorder((n * 8) + 10);
}

void Menu(int &flag)
{
	do
	{
		printf("1. Play again!");
		printf("\n");
		printf("2. Quits!");
		printf("\n");
		scanf_s("%d", &flag);

	} while (flag != 1 && flag != 2);
}

void main()
{
	char arr2D[rows][columns];
	int number = 0;
	int flag = 1;

	SetConsoleCP(437);
	SetConsoleOutputCP(437);

	while (flag == 1)
	{
		int posR = 0;
		int posC = 0;

		Input(number, "Table");
		system("cls");

		Select(arr2D, number, posR, posC, -1);

		SET_COLOR(15);
		Menu(flag);
		system("cls");
	}
	exit(0);
	_getch();
}