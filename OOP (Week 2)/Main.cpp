#include <iostream>
#include "Character.h"

int main()
{
	Ninja ninja("Sekiro"); // Make Talk method say their name then stuff to say
	Pirate pirate("Patchy"); // Make Talk method say their name then stuff to say

	bool gameRunning = true; // Set game loop yo true

	// Add a 'while' loop to create a game loop
	while (gameRunning)
		// Menu options go here
		// Display menu options
	{
		cout << "1. Talk to the ninja" << endl;
		cout << "2. Talk to the pirate" << endl;
		cout << "3. Quit the game" << endl;

		int choice;
		cout << "Please enter your choice: ";
		cin >> choice; // Get user's choice

		switch (choice)
		{
		case 1:
			ninja.Talk("I am a stealthy ninja!"); // Display methods
			ninja.ThrowStars();
			break;

		case 2:
			pirate.Talk("Avast ye, Matey!"); // Display methods
			pirate.UseSword();
			break;

		case 3: // gameRunning flag is set to false, the loop will then exit
			gameRunning = false;
			break;

		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	}

	cout << "Thank you for playing the game!" << endl;

	return 0; // Shows code ended with no errors
}