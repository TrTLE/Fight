#ifndef DEF_MONSTER
#define DEF_MONSTER

#include <string>

class Monster
{
public:
	Monster();
	Monster(std::string p_name, int p_life, int p_damage, int p_experienceToGive);
	~Monster();
	bool isAlive() const;
	void isAttack(int p_damage);
	std::string getName() const;
	int getLife() const;
	int giveExperience();

private:
	std::string name;
	int life, damage, experienceToGive;
};

#endif // !DEF_MONSTER