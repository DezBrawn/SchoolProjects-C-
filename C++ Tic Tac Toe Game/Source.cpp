// TIC TAC TOE Game

#include <iostream>

using namespace std;

char square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }; // # of squares on board

int checkwin() // Function to return the game status
{
	if (square[1] == square[2] && square[2] == square[3])
	{
		return 1;
	}
	else if (square[4] == square[5] && square[5] == square[6])
	{
		return 1;
	}
	else if (square[7] == square[8] && square[8] == square[9])
	{
		return 1;
	}
	else if (square[1] == square[4] && square[4] == square[7])
	{
		return 1;
	}
	else if (square[2] == square[5] && square[5] == square[8])
	{
		return 1;
	}
	else if (square[3] == square[6] && square[6] == square[9])
	{
		return 1;
	}
	else if (square[1] == square[5] && square[5] == square[9])
	{
		return 1;
	}
	else if (square[3] == square[5] && square[5] == square[7])
	{
		return 1;
	}
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
		&& square[4] != '4' && square[5] != '5' && square[6] != '6'
		&& square[7] != '7' && square[8] != '8' && square[9] != '9')
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

void board() // This function will draw the board with the players mark
{
	system("cls");
	cout << "\n\n\tTic Tac Toe Game \n\n"; // This is the game header

	// This indicates that Player 1 marks "X", Player 2 marks "O"
	cout << "Player 1(X) - Player 2(O)" << endl << endl;
	cout << endl; // This ends the line

	// Drawing of the board
	cout << "   |   |   " << endl; // Beginning of Row 1
	cout << " " << square[1] << " | " << square[2] << " | " << square[3] << endl;

	cout << "___|___|___" << endl;
	cout << "   |   |   " << endl;

	cout << " " << square[4] << " | " << square[5] << " | " << square[6] << endl;

	cout << "___|___|___" << endl;
	cout << "   |   |   " << endl;

	cout << " " << square[7] << " | " << square[8] << " | " << square[9] << endl;

	cout << "   |   |   " << endl << endl; // End of Row 3
}

int main() // Function that starts the program
{
	int player = 1, i, choice; // Function that allows player marks

	char mark;

	// This allows player marks to change the numbered squares to "X" or "O"
	do
	{
		board();
		player=(player%2)?1:2;

		cout << "Player " << player << ", enter the number: "; // Asks player to enter a square to mark
		cin >> choice; // Changes squares to match player choice

		mark = (player == 1) ? 'X' : 'O'; // Changes squares to "X" or "O" depending on player choice

		if (choice == 1 && square[1] == '1')
		{
			square[1] = mark;
		}
		else if (choice == 2 && square[2] == '2')
		{
			square[2] = mark;
		}
		else if (choice == 3 && square[3] == '3')
		{
			square[3] = mark;
		}
		else if (choice == 4 && square[4] == '4')
		{
			square[4] = mark;
		}
		else if (choice == 5 && square[5] == '5')
		{
			square[5] = mark;
		}
		else if (choice == 6 && square[6] == '6')
		{
			square[6] = mark;
		}
		else if (choice == 7 && square[7] == '7')
		{
			square[7] = mark;
		}
		else if (choice == 8 && square[8] == '8')
		{
			square[8] = mark;
		}
		else if (choice == 9 && square[9] == '9')
		{
			square[9] = mark;
		}
		else
		{
			cout << "INVALID MOVE!"; // This pops up if a square has already been claimed

			player--;
			cin.ignore(); // Ignores the invalid number entry, or the character input
			cin.get();
		}

		i = checkwin(); // Checks to see if there's a winner
		player++;
	} while (i == -1);
	board();
	if (i == 1)
	{
		cout << "\aCONGRATULATIONS! PLAYER " << --player << " WINS!"; // Pops up when someone wins the game
	}
	else
	{
		cout << "\aGAME DRAW!"; // Pops up when the game ends with a draw
	}
	cin.ignore();
	cin.get();
	return 0; // This indicates that the program ended with no problems
}