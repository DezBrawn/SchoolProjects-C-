#ifndef Character_h // includes #endif statement
#define Character_h // defines character class

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Character // the character class
{
public: // public specifier
	Character();
	Character(string newName, int newHealth, int newDamage, int newArrows);

	// call functions
	void attack(Character& target);
	void rangedAttack(Character& target);
	void set_health(int newHealth);

	int get_health() const; // create public variables
	string get_name() const;
	void display() const;

private: // private specifier
	string name; // create private variables
	int health;
	int damage;
	int arrows;
};
#endif
