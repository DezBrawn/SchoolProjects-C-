#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class GameStructure
{
	// empty class
};

// Create Character class, inherits from GameStructure class
class Character : public GameStructure
{
	// Create one private property called Health
private:
	int Health;

	// Create public method to access & update the private Health property
public:
	string Name;

	Character();

	void setHealth(int newHealth);

	int getHealth();

	virtual int attack(); // Create a virtual attack method

	// Create 2 methods named Talk
	void Talk(string stuffToSay); // Add method signature (string stuffToSay)

	void Talk(string name, string stuffToSay); // Add method signature (string name, string stuffToSay)

};

// Created Ninja class, inherits from Character class
class Ninja : public Character
{
public:
	Ninja(string name);

	int attack() override; // Create override attack method

	// Created method: ThrowStars
	void ThrowStars();
};

// Created Pirate class, inherits from Character class
class Pirate : public Character
{
public:
	Pirate(string name);

	int attack() override; // Create override attack method

	// Created method: UseSword
	void UseSword();
};

#endif
