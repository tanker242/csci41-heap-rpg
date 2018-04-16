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
void Entity::setHp (int m_hp){
	hp = m_hp;
};
int Entity::getHp(){
	return hp;
};

//
void Entity::setMp (int m_mp){
	mp = m_mp;
};
int Entity::getMp (){
	return mp;
};

//
void Entity::setLvl (int m_lvl){
	lvl = m_lvl;
};
int Entity::getLvl (){
	return lvl;
};

//
void Entity::setSpd (int m_spd){
	spd = m_spd;
};
int Entity::getSpd (){
	return spd;
};

//
void Entity::setStr(int m_str){
	str = m_str;
};
int Entity::getStr (){
	return str;
};

//
void Entity::setIntel (int m_intel)
{
	intel = m_intel;
};
int Entity::getIntel (){
	return intel;
};

//
void Entity::setAgi (int m_agi)
{
	agi = m_agi;
};
int Entity::getAgi (){
	return agi;
};

//
void Entity::set_isDead (bool m_isDead)
{
	isDead = m_isDead;
};
bool Entity::get_isDead (){
	return isDead;
};

//
void Entity::set_isAlly (bool m_isAlly)
{
	isAlly = m_isAlly;
};
bool Entity::get_isAlly (){
	return isAlly;
};

//
void Entity::setRow (bool m_row)
{
	row = m_row;
};
bool Entity::getRow (){
	return row;
};



//Start player classes

//Player::Player(){

//};


//Start NPC classes

// Mimic, centaur ???
