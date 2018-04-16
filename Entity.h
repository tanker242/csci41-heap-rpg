#ifndef _CLASSES
#define _CLASSES
//Start class prototypes
//Message me in discord if you have more to add or have suggestions

class Entity {

public:

	//Default Constructor
Entity();

	//Variables
int hp;
int mp;
int xp;
int lvl;
int spd; // might end up being an int depending on heap
int str; // stat will increase HP and warrior melee
int intel; // stat increases MP and spell damage
int agi; // stat increases speed and agile attack damage
bool isDead;
bool isAlly;
bool row; //Front row = 0 and back row = 1

  //Methods
void setHP (int _hp);
int getHP ();
void setMP (int _mp);
int getMP ();
void setLvl (int _lvl);
int getLvl ();
void setSpeed (int _spd);
int getSpeed ();
void setStr (int _str);
int getStr ();
void setIntel (int _intel);
int getIntel ();
void setAgi (int _agi);
int getAgi ();
void set_isDead (bool _isDead);
bool get_isDead ();
void set_isAlly (bool _isAlly);
bool get_isAlly ();
void setRow (bool _row);
bool getRow ();

};

//Start player classes
enum PlayerClass { warrior, mage, rogue, cleric, ranger, priest };

class Player : public Entity {

protected:
//Player characters set to 1 through the corresponding function when
//object is declared. Bool set to 1 for a specific class.
//	bool warrior;
//	bool mage;
//	bool rogue;
//	bool cleric;
//	bool ranger;
//	bool priest;

	PlayerClass selection;


public:

	PlayerClass getClass(); //return int for enum class, array of 0-5
	void setClass(); //funtions to set bool for 1 class. 
};


//Start NPC classes
enum NpcClass { typeNPC, bossNPC };

class Npc : public Entity {

protected:

	NpcClass selection;

public:

	void getNPC();
	int setNPC();
};

	

#endif
