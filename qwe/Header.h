#pragma once
#include <iostream>
#include<conio.h>
#include <time.h>
#include <windows.h>
#include <iomanip>
//using namespace std;

enum ConsoleColor {
	Blue = 9, Red = 12, White = 15
};
void setColor(unsigned color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleTextAttribute(hConsole, color);
}


