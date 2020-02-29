#include "Character.h"
#include <time.h>

Character::Character () {
	name = "";
	life = 100;
	damage = 100;
	experience = 0;
	level = 1;
}

Character::Character(std::string p_name, int p_life, int p_damage, int p_experience, int p_level): name(p_name), life(p_life), damage(p_damage), experience(p_experience), level(p_level)
{
}
	
Character::~Character() {

}

void Character::attack(Monster &p_monster)
{
	srand(time(NULL));
	int damageDeal = rand() % damage;
	p_monster.isAttack(damageDeal);
}
	
bool Character::isAlive() const {
	return life > 0;
}

void Character::winExperience(Monster p_monster)
{
	experience += p_monster.giveExperience();
}

void Character::levelUp()
{
	level++;
	life += (life / 100.0) * 20;
	damage += (damage / 100.0) * 10;
	printf("Vous avez gagne un niveau ! youhou :D \n\n");
	printf("Vos stats sont maintenant : `\n");
	showStat();
}

void Character::showStat()
{
	printf("Niveau %i\nExperience %i\nSante %i\nAttaque %i\n\n", level, experience, life, damage);
}

std::string Character::getName()
{
	return name;
}

int Character::getLevel()
{
	return level;
}

int Character::getExperience()
{
	return experience;
}

int Character::getLife()
{
	return life;
}

int Character::getDamage()
{
	return damage;
}
