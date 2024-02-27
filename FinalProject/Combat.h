#ifndef COMBAT_h // includes #endif statement
#define COMBAT_h // defines combat class

#include <iostream>
#include <vector>
#include "Character.h"

using namespace std;

class Combat // the combat class
{
public: // public specifier
	Combat();
	Combat(int newNumberOfMonsters);

	// call functions to execute
	void attackAll();
	void start();
	void checkAliveMonster();

	void printMonsterList() const;

private: // private specifier
	int NumberOfMonsters;
	vector<Character> monsterList;
	Character hero;
	int tokens;
};
#endif
