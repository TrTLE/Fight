#ifndef DEF_CHARACTER
#define DEF_CHARACTER

#include "Monster.h"
#include <string>

class Character
{
public:
	Character();
	Character(std::string p_name, int p_life, int p_damage, int p_experience, int p_level);
	~Character();
	void attack(Monster &p_monster);
	bool isAlive() const;
	void winExperience(Monster p_monster);
	void levelUp();
	void showStat();
	std::string getName();
	int getLevel();
	int getExperience();
	int getLife();
	int getDamage();

private:
	std::string name;
	int life, damage, experience, level;
};

#endif // !DEF_CHARACTER