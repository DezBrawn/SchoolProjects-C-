#include <iostream>
#include "Character.h"

using namespace std;

Character::Character()
{
	Health = 100;
}

void Character::setHealth(int newHealth)
{
	// Check Health before setting the value
	// If the new Health value is less than zero, display "Character has expired"
	if (newHealth < 0)
	{
		Health = 0;
		cout << "Character has Expired..." << endl;
	}
	else
	{
		Health = newHealth;
	}
}

int Character::getHealth()
{
	return Health;
}

int Character::attack()
{
	return 10;
}

void Character::Talk(string stuffToSay)
{
	cout << Name << ": " << stuffToSay << endl;
}

void Character::Talk(string name, string stuffToSay)
{
	cout << name << ": " << stuffToSay << endl;
}

Ninja::Ninja(string name)
{
	Name = name;
}

int Ninja::attack()
{
	return 25; // Override attack method, set return values at 25 hit points
}

void Ninja::ThrowStars()
{
	cout << "I'm throwing stars!" << endl;
}

Pirate::Pirate(string name)
{
	Name = name;
}

int Pirate::attack()
{
	return 25; // Override attack method, set return values at 25 hit points
}

void Pirate::UseSword()
{
	cout << "I'm swooshing my sword!" << endl;
}