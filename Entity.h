//#include <iostream>
//#include <cstdlib>


#ifndef _CLASSES
#define _CLASSES
//Start class prototypes
//Message me in discord if you have more to add or have suggestions

class Entity {

public:


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
void setHp(int _hp);
int getHp ();
void setMp (int _mp);
int getMp ();
void setLvl (int _lvl);
int getLvl ();
void setSpd (int _spd);
int getSpd ();
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

//Constructor
Entity(){
int hp = 0;
int mp = 0;
int xp = 0; //** Note Not currently used - needs to be added
int lvl = 1;
int spd = 0; // might end up being an int depending on heap
int str = 0; // stat will increase HP and warrior melee
int intel = 0; // stat increases MP and spell damage
int agi = 0; // stat increases speed and agile attack damage
bool isDead = 0;
bool isAlly = 0;
bool row = 0; //Front row = 0 and back row = 1
}
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
// Tried to nest a constructor, but it didn't work very well
	/*
	void meow(int x){
		if(true){
		Player(){
		hp = 13337;
		};
		}else{
			Player(){
				hp = 22;
			};
			
	}
	};
*/
// Was wanting to use enum to select a condition in order to set default stats for desired character
//	Player(){};
//	~Player(){};

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

	
/*Function designed to test class
void TestEntity(){
cout << "Printing all values for the following: object test of type Player." << endl;
Player test;
cout << "HP:" << test.getHp() << endl;
cout << "MP:" << test.getMp() << endl;
cout << "Lvl:" << test.getLvl() << endl;
cout << "Spd:" << test.getSpd() << endl;
cout << "Xp:" << "Is currently not in use" << endl;
cout << "Str:" << test.getStr() << endl;
cout << "Intel:" << test.getIntel() << endl;
cout << "Agi:" << test.getAgi() << endl;
cout << "isDead:" << get_isDead()  << endl;
cout << "isAlly:" << get_isAlly()  << endl;
cout << "row:" << getRow()  << endl;
};
*/
#endif
