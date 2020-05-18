#include"Header.h"

unsigned int checkTime;

void main()
{
	short int cursor = Menu();
	const int n = 5;
	char* arr = new char[n];
	char* brr = new char[n];
	short int mistakes = 0, correct = 0;

	for (int i = 0; i < n; i++)
	{
		i % 8 == 4 && i > 0 ? brr[i] = ' ' : brr[i] = (rand() % 26 + 65); // Random
	}

	if (cursor == 0)Game(n, brr, arr, mistakes, correct);
	else if (cursor == 4)exit(0);

	int Second = checkTime / 1000;
	int Millisecond = checkTime - (Second * 1000);

	std::cout << std::endl << "\nMistakes: " << mistakes;
	std::cout << "\nTotal time: " << Second << "," << Millisecond << "Seconds";
	std::cout << "\nAvg symbols per seconds: " << double(n) / double(Second);
	std::cout << "\nAvg correct symbols per seconds: " << double(correct) / double(Second);
}
void Game(int n, char* brr, char* arr, short int& mistakes, short int& correct)
{
	Print(brr, n);
	short int _cin;
	unsigned int start = clock();
	for (int i = 0; i < n - 1; i++)
	{
		_cin = _getch();

		if (_cin == 8 && i != 0)    // if enter backspace
		{
			system("cls");  
			Print(brr, n);		
			for (int j = 0; j < i - 1; j++)
			{
				arr[j] == brr[j] ? setColor(Green) : setColor(Red);   // save color in console
				std::cout << arr[j];      // print brr with size - 1
			}
			gotoxy(i - 1, 3);  // set line
			i-= 2;
			continue;
		}
		else if ((_cin < 65 || _cin > 90)  &&  _cin != 32 ) 
		{
			i--; continue;
		}
		*(arr + i) = char(_cin);
		arr[i] == brr[i] ? (setColor(Green), correct++) : (setColor(Red), mistakes++);
		std::cout << arr[i];
	}
	unsigned int end = clock();
	unsigned int time = end - start;
	checkTime = time;
	setColor(White);
	return;
}
void gotoxy(short int x, short int y)
{
	COORD coord;	// Определяет координаты ячейки символа в буфере экрана консоли
	coord.X = x; coord.Y = y; //GetStdHandle (STD_OUTPUT_HANDLE,coord) получает дескриптор, для записи на консоль.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); //Затем SetConsoleCursorPosition использует этот дескриптор и указанные координаты, чтобы поместить мигающий курсор в командную строку.
}
int  Menu(short int cursor)
{
	short int get = 0;
	while (get != 13)
	{   ////////////////////////////////////////////////////////////////////////////////////////////
		std::cout << (char)218 << "---------------------------------" << (char)191;
		std::cout << "\n|\t\tSTART\n|\n|\t\tLEVELS\n|\n|\t\tEXIT";
		for (int i = 1; i < 6; i++) {
			gotoxy(33, i);
			std::cout << " |";								// Меню игры 
		}
		std::cout << std::endl << (char)192 << "---------------------------------" << (char)217;
		////////////////////////////////////////////////////////////////////////////////////////////
		gotoxy(13, cursor + 1);			// Позиция курсора
		std::cout << ">>";
		switch (get = _getch())
		{
		case 72: // ↑
			if (cursor == 0) break;		// что бы курсор не убежал верх.
			else cursor -= 2; break;     // измениния кординаты Х если нажать вверх 
		case 80: // ↓
			if (cursor == 4) break;		// что бы курсор не убежал в низ.
			else cursor += 2; break;		// измениния кординаты Х если нажать вниз 
		}
		system("cls");
	}
	return cursor;
}
void Print(char* brr, int n)
{
	setColor(White);
	std::cout << std::endl;
	for (int i = 0; i < n; i++)  {

		std::cout << *(brr + i);
	}

	std::cout << std::endl << std::endl;
}


