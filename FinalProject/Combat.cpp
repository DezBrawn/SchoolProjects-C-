#include "Combat.h" // include combat header file

Combat::Combat(int newNumberOfMonsters) // updates combat with current monsters left
	// hero strings to display, updated based on combat
	:hero("Hero", 30, 3, 5), NumberOfMonsters(newNumberOfMonsters), tokens(2)
{
	for (int i = 0; i < newNumberOfMonsters; i++) // updates monster list
	{
		Character M("Monster", 5, 2, 0); // updates monster strings
		monsterList.push_back(M); // updates monster list
	}
}

void Combat::start() // function to start combat
{
	int choice, iMonster; // variables
	srand(time(0)); // allows random monster generation

	while (NumberOfMonsters > 0 && hero.get_health() > 0) // while loop
	{
		for (int i = 0; i < NumberOfMonsters; i++) // to monster to attack hero
			monsterList[i].attack(hero); // allows monster to attack character

		cout << "-----\n"; // line break for easier reading

		if (hero.get_health() <= 0) // if statement for hero health greater than 0
			break;

		hero.display(); // display hero stats
		cout << hero.get_name() << " has " << tokens << " tokens left.\n"; // display hero tokens
		cout << "-----\n"; // line break for easier reading

		// asking the user to input next move
		cout << "What's your next move? 1. Attack, 2. Fire Arrow, 3. Attack all, Q. Exit: ";
		cin >> choice; // asks user to input move choice
		if (choice == 1 || choice == 2) // if statement for choice 1 or 2
		{
			cout << "Which monster do you want to attack? (0-" << NumberOfMonsters - 1 << "): " << endl;
			cin >> iMonster; // asks user to input monster choice
			if (cin.fail() || iMonster >= NumberOfMonsters) // if statement for invalid number
			{
				cout << "Input Error!\n"; // prints input error
				break;
			}
		}

		cout << "-----\n"; // line break for easier reading

		switch (choice) // switch statement allows for use of many code blocks
		{
		case 1: // choice 1
			hero.attack(monsterList[iMonster]);
			break;

		case 2: // choice 2
			hero.rangedAttack(monsterList[iMonster]); // not sure why the warning is here
			break;

		case 3: // choice 3
			attackAll();
			break;

		default: // for invalid input
			cout << "Input Error!\n"; // prints input error
			break;
		}
		checkAliveMonster(); // calls function to check monster health
		cout << "-----\n"; // line break for easier reading
	} // end of while loop
	if (NumberOfMonsters == 0) // if statement, if all monsters health = 0
		cout << "Good job! You killed all of the monsters!" << endl; // tells user all monsters are defeated
	if (hero.get_health() <= 0) // if users health reaches 0, ends game
		cout << "You died.. game over!" << endl; // tells user they died, the game ended

	cout << "Thanks for playing!" << endl;

} // end function

void Combat::attackAll() // function for attack all monsters
{
	if (tokens != 0)
	{
		vector<int> monsterList{ 0, 1, 2 }; // vector for monster list
		for (int i = 0; i < NumberOfMonsters - 1; i++) // for statement to remove monster from list
		{
			cout << hero.get_name() << " attacks " << monsterList[i] << endl; // user attacks monster
		}
		--tokens; // tokens are taken from user
	}
	else if (tokens == 0) // else if statement for 0 tokens left
	{
		cout << "Hero is out of tokens!" << endl;
	}
} // end function

void Combat::checkAliveMonster() // function to check monsters still alive
{
	for (int i = 0; i < NumberOfMonsters - 1; i++) // for statement to update monster list
	{
		if (monsterList[i].get_health() <= 0) // if statement to get monster health
		{
			--NumberOfMonsters; // removes monsters upon reaching 0 health
			cout << "You killed a monster!" << endl;
			hero.set_health((hero.get_health() + 5)); // hero gains +5 health back
			cout << "Hero gained 5 health!" << endl;
			++tokens; // hero gains a token
			cout << "Hero gained 1 token!" << endl;
		}
	}
} // end of function

void Combat::printMonsterList() const /// function to display monster stats
{
	for (int i = 0; i < NumberOfMonsters - 1; i++) // for statement to check/display monsters health
	{
		cout << "Monster" << monsterList[i].get_name() << " health: " << monsterList[i].get_health();
	}
} // end function