//#include <iostream>
//#include <cstdlib>
#include <array>
#include <string>
#include <algorithm>
#include <string>
#include <cstdlib>
//#include "Enum.h"
//#pragma once

using namespace std;

#ifndef _CLASSES
#define _CLASSES
//Start class prototypes
//Message me in discord if you have more to add or have suggestions

enum stat_type {STR = 0, INT = 1, AGI = 2, SPD = 3, ARM = 4, MR = 5, XHP = 6, XMP = 7};
enum postion {FRONT, BACK};

class Entity {

  protected:


	//Variables
	string name;
	int hp;
	int mp;
	int xp;
	int lvl;
	array<int, 8> stats;
	array<int, 8> stat_gain;
	array<int, 8> delta_stat;
	bool isDead;
	bool isAlly; // true for player, false for enemy
	bool row; //Front row = 0 and back row = 1


  public:
	//Methods
	//Use enums as needed

	void setHp(int m_hp);
	int getHp();
	void setMp(int m_mp);
	int getMp();
	void setLvl(int m_lvl);
	int getLvl();
//void setSpd (int m_spd);
//int getSpd ();
//void setStr (int m_str);
//int getStr ();
//void setIntel (int m_intel);
//int getIntel ();
//void setAgi (int m_agi);
//int getAgi ();
	void set_isDead(bool m_isDead);
	bool get_isDead();
	void set_isAlly(bool m_isAlly);
	bool get_isAlly();
	void setRow(bool m_row);
	bool getRow();

//New methods

	int get_stat(stat_type in);
	void change_stat(stat_type stat, int change);
	void end_battle();
	string get_name();
	void lvl_up();
	int get_level();
//	int getHp();
	int damage(int in);
	void subMp(int in);
//	int getMp();
	void changeRow();

//Constructor
//You can enter the arrays like this
//{STR,INT,AGI,SPD,ARM,MR,XHP,XMP}

	Entity(array<int, 8> base, array<int, 8> per_lvl, int lvl, bool side, string named)
		: stats(base), stat_gain(per_lvl), lvl(lvl), isAlly(side), isDead(false), row(FRONT), xp(0), name(named) {
//		delta_stat.file(0); // No member function in scope yet
		hp = stats[XHP];
		mp = stats[XMP];
	}
};

/* OLD CODE
Entity(){
hp = 0;
mp = 0;
xp = 0; //** Note Not currently used - needs to be added
lvl = 1;
spd = 0; // might end up being an int depending on heap
str = 0; // stat will increase HP and warrior melee
intel = 0; // stat increases MP and spell damage
agi = 0; // stat increases speed and agile attack damage
isDead = 0;
isAlly = 0;
row = 0; //Front row = 0 and back row = 1
}
};
*/


//Start player classes
enum ActorClass { warrior, mage, rogue, monk, ranger, priest };

class Actor : public Entity {

  protected:
//Player characters set to 1 through the corresponding function when
//object is declared. Bool set to 1 for a specific class.
//	bool warrior;
//	bool mage;
//	bool rogue;
//	bool cleric;
//	bool ranger;
//	bool priest;

	ActorClass selection;


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

	ActorClass getClass(); //return int for enum class, array of 0-5
	void setClass(); //funtions to set bool for 1 class.
};


//Start NPC classes
//enum NpcClass { typeNPC, bossNPC };
//
//class Npc : public Entity {
//
//protected:
//
//	NpcClass selection;
//
//public:
//
//	void getNPC();
//	int setNPC();
//};


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
