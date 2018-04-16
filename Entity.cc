#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Entity.h"

using namespace std;

//Start Entity implementation

Entity::Entity(){

int hp = 0;
int mp = 0;
int xp = 0;
int lvl = 1;
int speed = 0; // might end up being an int depending on heap
int str = 0; // stat will increase HP and warrior melee
int intel = 0; // stat increases MP and spell damage
int agi = 0; // stat increases speed and agile attack damage
bool isDead = 0;
bool isAlly = 0;
bool row = 0 //Front row = 0 and back row = 1
};
  //Methods
void Entity::setHP ();
int Entity:: getHP (){
	return hp;
};

void Entity:: setMP ();
int Entity::getMP (){
	return mp;
};

void Entity::setLvl ();
int Entity:: getLvl (){
	return lvl;
};

void Entity::setSpeed ();
int Entitiy::getSpeed (){
	return spd;
};

void Entity::setStr ();
int Entity::getStr (){
	return str;
};

void Entity::setIntel ();
int Entity::getIntel (){
	return intel;
};

void Entity::setAgi ();
int Entity::getAgi (){
	return agi;
};

void Entity::set_isDead ();
bool Entity::get_isDead (){
	return isDead;
};

void Entity::set_isAlly ();
bool Entity::get_isAlly (){
	return isAlly;
};

void Entity::setRow ();
bool Entity::getRow (){
	return row;
};



//Start player classes

Player::Player(){

}


//Start NPC classes

// Mimic, centaur ???
