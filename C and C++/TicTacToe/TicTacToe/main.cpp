#include<iostream>

using namespace std;

char square[9] = { '1','2','3','4','5','6','7','8','9' };

int check();

void print_board();

void reset();


int main()
{
	
	int player = 1,i, choice,P1=0,P2=0;
	char mark,cont_play;
	do
	{
		reset();
		print_board();
		do
		{
			print_board();
			if (player % 2 == 0)
			{
				player = 2;
			}
			else
			{
				player = 1;
			}
			cout << "\n\n\nPlayer " << player << " Enter";
			std::cin >> choice;
			if (player == 1)
			{
				mark = 'X';
			}
			else
			{
				mark = 'O';
			}
			if (choice == 1 && square[0] == '1')
			{
				square[0] = mark;
			}
			else if (choice == 2 && square[1] == '2')
			{
				square[1] = mark;
			}
			else if (choice == 3 && square[2] == '3')
			{
				square[2] = mark;
			}
			else if (choice == 4 && square[3] == '4')
			{
				square[3] = mark;
			}
			else if (choice == 5 && square[4] == '5')
			{
				square[4] = mark;
			}
			else if (choice == 6 && square[5] == '6')
			{
				square[5] = mark;
			}
			else if (choice == 7 && square[6] == '7')
			{
				square[6] = mark;
			}
			else if (choice == 8 && square[7] == '8')
			{
				square[7] = mark;
			}
			else if (choice == 9 && square[8] == '9')
			{
				square[8] = mark;
			}
			else
			{
				cout << "Invalid choice";
				player--;
				std::cin.ignore();
				std::cin.get();
			}
			i = check();
			player++;
		} while (i == -1);
		print_board();
		if (i == 1)
		{
			cout << "\n\nPlayer " << --player << " wins";
		}
		else if (i == 0)
		{
			cout << "\n\nDraw";
		}
		if (player == 1 && i == 1)
		{
			P1++;
		}
		else if (player == 2 && i == 1)
		{
			P2++;
		}
		cout << "\nPlayer 1 " << " Score = " << P1;
		cout << "\nPlayer 2 " << " Score = " << P2;
		cout << "\nDo you want to continue playing Y/N?";
		cin >> cont_play;
	} while (cont_play == 'Y');
	std::cin.ignore();
	std::cin.get();


	return 0;

}


int check()
{
	if (square[0] == square[1] && square[1] == square[2])
		return 1;
	else if (square[3] == square[4] && square[4] == square[5])
		return 1;
	else if (square[6] == square[7] && square[7] == square[8])
		return 1;
	else if (square[0] == square[4] && square[4] == square[8])
		return 1;
	else if (square[2] == square[4] && square[4] == square[6])
		return 1;
	else if (square[0] == square[3] && square[3] == square[6])
		return 1;
	else if (square[1] == square[4] && square[4] == square[7])
		return 1;
	else if (square[2] == square[5] && square[5] == square[8])
		return 1;
	else if (square[0] != '1' &&square[1] != '2' &&square[2] != '3' &&square[3] != '4' &&square[4] != '5' &&square[5] != '6' &&square[6] != '7' &&square[7] != '8' &&square[8] != '9')
		return 0;
	else
		return -1;

}
void print_board()
{
	system("cls");
	cout << "---TIC TAC TOE---\n\n";
	cout << " " << square[0] << "|" << " " << square[1] << " " << "|" << " " << square[2];
	cout << "\n_________\n";
	cout << " " << square[3] << "|" << " " << square[4] << " " << "|" << " " << square[5];
	cout << "\n_________\n";
	cout << " " << square[6] << "|" << " " << square[7] << " " << "|" << " " << square[8];
}


void reset()
{
	square[0] = '1';
	square[1] = '2';
	square[2] = '3';
	square[3] = '4';
	square[4] = '5';
	square[5] = '6';
	square[6] = '7';
	square[7] = '8';
	square[8] = '9';

}

