#include"Header.h"


void gotoxy(int x, int y);
void Menu()
{
	int cursor = 0;
	int get = 0;
	while (get != 13)
	{  ////////////////////////////////////////////////////////////////////////////////////////////
		std::cout <<(char)218 <<"---------------------------------" << (char)191;			
		std::cout << "\n|\t\tSTART\n|\n|\t\tLEVELS\n|\n|\t\tEXIT";
		for (int i = 1; i < 6; i++) {
			gotoxy(33, i);
			std::cout << " |";								// Меню игры 
		}
		std::cout << std::endl << (char)192 << "---------------------------------" << (char)217;
	   ////////////////////////////////////////////////////////////////////////////////////////////

		gotoxy(13, cursor+1);			// Позиция курсора
		std::cout << ">>";
		get = _getch();
		switch (get)
		{
		case 72: // ↑
			if (cursor == 0) break;		// что бы курсор не убежал верх.
			else cursor -= 2;break;     // измениния кординаты Х если нажать вверх 
	    case 80: // ↓
			if (cursor == 4) break;		// что бы курсор не убежал в низ.
			else cursor += 2;break;		// измениния кординаты Х если нажать вниз 
		}
		system("cls");	
	}
}

void Field() {



}

int main()
{
	Menu();
	
}
void gotoxy(int x, int y)
{
	COORD coord;	// Определяет координаты ячейки символа в буфере экрана консоли
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	//GetStdHandle (STD_OUTPUT_HANDLE,coord) получает дескриптор, для записи на консоль.
	//Затем SetConsoleCursorPosition использует этот дескриптор и указанные координаты, чтобы поместить мигающий курсор в командную строку.
}
