#include "Monster.h"

Monster::Monster()
{
	name = "";
	life = 100;
	damage = 100;
	experienceToGive = 50;
}

Monster::Monster(std::string p_name, int p_life, int p_damage, int p_experienceToGive): name(p_name), life(p_life), damage(p_damage), experienceToGive(p_experienceToGive)
{
}

Monster::~Monster()
{
}

bool Monster::isAlive() const
{
	return life > 0;
}

void Monster::isAttack(int p_damage)
{
	life -= p_damage;
	printf("Le mosntre s'exclame : Aie ! ca pique \n");
}

std::string Monster::getName() const
{
	return name;
}

int Monster::getLife() const
{
	return life;
}

int Monster::giveExperience()
{
	return experienceToGive;
}
