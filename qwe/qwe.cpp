#include"Header.h"
unsigned int checkTime;

class Levels
{
	public:
		void Random(char* brr, int n)
		{
			srand(time(NULL));
			for (int i = 0; i < n; i++) {
				i % 8 == 0 && i != 0 ? *(brr + i) = char(32) : *(brr + i) = char(rand() % 25 + 65); // ASCII + Space int arr
			}
		}
};

void main()
{
	short int cursor = Menu();
	int n = 24;
	char* arr = new char[n];
	char* brr = new char[n];
	short int mistakes = 0, correct = 0;

	brr.Random(brr, n);
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
	short int cin;
	unsigned int start = clock();
	for (int i = 0; i < n; i++)
	{
		cin = _getch();
		if (cin == 8)
		{
			system("cls");
			i--;
			Print(brr, n);
			for (int j = 0; j < i; j++)
			{
				arr[j] == brr[j] ? setColor(Green) : setColor(Red);
				std::cout << arr[j];
			}
			gotoxy(i, 3);
			i--; continue;
		}
		else if ((cin < 32 || cin > 90) || (cin > 32 && cin < 65))
		{
			i--; continue;
		}
		*(arr + i) = char(cin);
		arr[i] == brr[i] ? (setColor(Green), correct++) : (setColor(Red), mistakes++);
		std::cout << arr[i];
	}
	unsigned int end = clock();
	unsigned int time = end - start;
	checkTime = time;
	setColor(White);
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
	for (int i = 0; i < n; i++) {	
		std::cout << *(brr + i);
	}
	std::cout << std::endl << std::endl;
}