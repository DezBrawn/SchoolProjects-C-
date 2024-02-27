// include libraries to use

#include <iostream>

using namespace std;

const int ROCK = 1; // constant integer varaible for Rock, doesn't change
const int PAPER = 2; // constant integer variable for Paper, doesn't change
const int SCISSORS = 3; // constant integer variable for Scissors, doesn't change

int userChoice = 0; // integer variable for user choice

int getComputerChoice() // Function to get random computer choice
{
	srand (time(NULL)); // Provides random number generation
	int compChoice = rand() % 3 + 1; // integer variable for random computer choice
	return compChoice; // Prints computer choice
}

void determineWinner(int userChoice, int compChoice) // Function to determine winner based on choices
{
	if (userChoice == ROCK && compChoice == PAPER)
	{
		cout << "Computer wins! Paper wraps rock." << endl;
	}

	else if (userChoice == PAPER && compChoice == SCISSORS)
	{
		cout << "Computer wins! Scissors cut paper." << endl;
	}

	else if (userChoice == SCISSORS && compChoice == ROCK)
	{
		cout << "Computer wins! Rock smashes scissors." << endl;
	}

	else if (userChoice == ROCK && compChoice == SCISSORS)
	{
		cout << "YOU win! Rock smashes scissors." << endl;
	}

	else if (userChoice == PAPER && compChoice == ROCK)
	{
		cout << "YOU win! Paper wraps rock." << endl;
	}

	else if (userChoice == SCISSORS && compChoice == PAPER)
	{
		cout << "YOU win! Scissors cut paper." << endl;
	}

	else
	{
		cout << "Tie" << endl; // If both choices are the same
	}
}

void displayChoice(int choice) // To display selected choice
{
	string result;

	if (choice == ROCK)
	{
		result = "Rock";
	}

	else if (choice == PAPER)
	{
		result = "Paper";
	}

	else
	{
		result = "Scissors";
	}

	cout << result << endl;
}

int main()
{
	cout << '\t' << "Rock, Paper, Scissors" << endl; // Prints title = Rock, Paper, Scissors
	cout << "Game Menu" << endl; // Prints Game Menu
	cout << "1. Rock" << endl; // Displays choice by number = Rock
	cout << "2. Paper" << endl; // Displays choice by number = Paper
	cout << "3. Scissors" << endl; // Displays choice by number = Scissors

	cout << "Enter your choice: "; // Prompt to enter choice
	cin >> userChoice; // Gets user choice
	cout << "You selected: "; // Prints "You selected:"
	displayChoice(userChoice); // Displays user choice

	int compChoice = getComputerChoice(); // integer variable to get random computer choice

	cout << "The computer selected: "; // Displays "The computer selected:"
	displayChoice(compChoice); // Displays coomputer choice

	determineWinner(userChoice, compChoice); // Determines winner by choices
}