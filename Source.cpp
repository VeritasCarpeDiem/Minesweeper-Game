#include <iostream>
#include<string>
#include <Windows.h>
#include <time.h>
using namespace std;
/* Created by: Jin Kim
1. display array
2. read user input
3. IF it's safe: display safe area; IF it's bomb, explode(exit loop, display board with bombs)
4. gobackto step 1
*/
void displayTextColor(int color)//function to change text color
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
//Innovation: Difficulty, Top scores,function for color, option to play again
int main()
{
	//intialize array and assign const int data type to array size
	const int maxRow = 10;
	const int maxCol = 10;
	int row = 0;
	int col = 0;
	int score = 0;
	int highScore = 0;
	string answer = "Yes";
	string choice = "normal";
	int board[maxRow][maxCol];
	while (answer == "Yes")
	{
		cout << "Your Highest score: " << highScore << endl;
		cout << "Your score: " << score << endl;
		system("cls");
		cout << "Choose your difficulty (normal or hard)" << endl;
		cin >> choice;
		//Randomly generate bomb based on difficulty
		srand(time(NULL));
		if (choice == "normal")
		{
			for (int i = 0; i < 10; i++)
				board[rand() % maxRow][rand() % maxCol] = 1;
		}
		else
		{
			for (int i = 0; i < 30; i++)
				board[rand() % maxRow][rand() % maxCol] = 1;
		}
		// display initial array
		for (int row = 0; row < maxRow; row++)
		{
			for (int col = 0; col < maxCol; col++)
			{
				cout << char(219) << "  ";
			}
			cout << endl << endl;
		}
		// Enter user input
		cout << "Enter row and col" << endl;
		cin >> row >> col;
		while (board[row][col] != 1) //show board while user doesn't step on bomb
		{
			score += 10;
			if (score > highScore)
			{
				highScore = score;//update score once it passes highest score
			}
			system("cls");
			cout << "Your Highest score: " << highScore << endl;
			cout << "Your score: " << score << endl;
			board[row][col] = 2;
			for (int row = 0; row < maxRow; row++)
			{
				for (int col = 0; col < maxCol; col++)
				{
					if (board[row][col] == 2)//show green if user doesn't step on mine
					{
						displayTextColor(10);
						cout << char(219);
						displayTextColor(15);
						cout << "  ";
					}
					else
					{
						displayTextColor(15);
						cout << char(219);
						cout << "  ";
					}
				}
				cout << endl << endl;
			}
			cout << "Enter row and col" << endl;
			cin >> row >> col;
		}
		system("cls");
		//display board after user steps on bomb
		cout << "Your Highest score: " << highScore << endl;
		cout << "Your score: " << score << endl;
		for (int row = 0; row < maxRow; row++)
		{
			for (int col = 0; col < maxCol; col++)
			{
				if (board[row][col] == 2)
				{
					displayTextColor(10);
					cout << char(219);
					displayTextColor(15);
					cout << "  ";
				}
				else if (board[row][col] == 1)//show red if user steps on bomb
				{
					displayTextColor(12);
					cout << char(219);
					displayTextColor(15);
					cout << "  ";
				}
				else
				{
					displayTextColor(15);
					cout << char(219);
					cout << "  ";
				}
			}
			cout << endl << endl;
		}
		cout << "You stepped on the bomb at " << row << ", " << col << endl;
		cout << "Do you want to play again?(Yes/No)" << endl;
		cin >> answer;
		score = 0;
	}
	cout << "Your highest score is: " << highScore << endl;
	cout << "Thanks for playing!" << endl;
	return 0;
}