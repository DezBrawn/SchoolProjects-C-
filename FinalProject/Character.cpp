#include "Character.h"

Character::Character() // for character stats
{
	name = " ";
	health = 0;
	damage = 0;
	arrows = 0;
}

// update character stats with new stats
Character::Character(string newName, int newHealth, int newDamage, int newArrows)
{
	name = newName; // update stats with new stats
	health = newHealth;
	damage = newDamage;
	arrows = newArrows;
}

void Character::set_health(int newHealth) // function for character health
{
	health = newHealth;
} // end function

void Character::attack(Character& target) // function for character to attack
{
	target.health -= damage; // subtract from character health
	cout << name << " attacks " << target.name << " causing " << damage << " damage!" << endl;
	cout << target.name << " health: " << target.health << endl;
} // end function

void Character::rangedAttack(Character& target) // functions for character ranged attack
{
	if (arrows == 0) // if arrows = 0
		cout << name << " is out of arrows!" << endl;
	else // arrow does random damage number
	{
		int rangedDamage = rand() % 5 + 1;
		target.health -= rangedDamage; // health is decreased from target
		arrows--; // subtract from number of arrows
		// outputs target took damage
		cout << name << " shoots " << target.name << " causing " << rangedDamage << " damage! " << endl;
		cout << target.name << " health: " << target.health << endl; // displays new target health
	}
} // end function

void Character::display() const // function to display characters health and number of arrows
{
	cout << name << " health: " << health << endl;
	cout << name << " arrows: " << arrows << endl;
} // end function

string Character::get_name() const // get character name
{
	return name; // return name
}

int Character::get_health() const // get character health
{
	return health; // return health
}

