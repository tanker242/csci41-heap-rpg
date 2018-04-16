#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Entity.h"

using namespace std;

//Start Entity implementation
/*
Entity::Entity(){

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
};
*/
  //Methods
void Entity::setHp (int _hp){
	hp = _hp;
};
int Entity::getHp(){
	return hp;
};

//
void Entity::setMp (int _mp){
	mp = _mp;
};
int Entity::getMp (){
	return mp;
};

//
void Entity::setLvl (int _lvl){
	lvl = _lvl;
};
int Entity::getLvl (){
	return lvl;
};

//
void Entity::setSpd (int _spd){
	spd = _spd;
};
int Entity::getSpd (){
	return spd;
};

//
void Entity::setStr(int _str){
	str = _str;
};
int Entity::getStr (){
	return str;
};

//
void Entity::setIntel (int _intel)
{
	intel = _intel;
};
int Entity::getIntel (){
	return intel;
};

//
void Entity::setAgi (int _agi)
{
	agi = _agi;
};
int Entity::getAgi (){
	return agi;
};

//
void Entity::set_isDead (bool _isDead)
{
	isDead = _isDead;
};
bool Entity::get_isDead (){
	return isDead;
};

//
void Entity::set_isAlly (bool _isAlly)
{
	isAlly = _isAlly;
};
bool Entity::get_isAlly (){
	return isAlly;
};

//
void Entity::setRow (bool _row)
{
	row = _row;
};
bool Entity::getRow (){
	return row;
};



//Start player classes

//Player::Player(){

//};


//Start NPC classes

// Mimic, centaur ???
