#pragma once
#include <iostream>
#include<conio.h>
#include <time.h>
#include <windows.h>

enum ConsoleColor {
	Blue = 9, Red = 12, White = 15, Green = 10
};
void setColor(unsigned color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleTextAttribute(hConsole, color);
}
void Game(int n, char* brr, char* arr, short int& mistakes, short int& correct);
void gotoxy(short int x, short int y);
int  Menu(short int cursor = 0);
void Random(char* brr, int n);
void Print(char* brr, int n);

