#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <array>
#include "Entity.h"



using namespace std;

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
void Entity::setHp(int m_hp) {
	hp = m_hp;
};
int Entity::getHp() {
	return hp;
};

//
void Entity::setMp(int m_mp) {
	mp = m_mp;
};
int Entity::getMp() {
	return mp;
};

//
void Entity::setLvl(int m_lvl) {
	lvl = m_lvl;
};
int Entity::getLvl() {
	return lvl;
};

//
//void Entity::setSpd(int m_spd) {
//	spd = m_spd;
//};
//int Entity::getSpd() {
//	return spd;
//};

//
//void Entity::setStr(int m_str) {
//	str = m_str;
//};
//int Entity::getStr() {
//	return str;
//};
//
//
//void Entity::setIntel(int m_intel) {
//	intel = m_intel;
//};
//int Entity::getIntel() {
//	return intel;
//};
//
//
//void Entity::setAgi(int m_agi) {
//	agi = m_agi;
//};
//int Entity::getAgi() {
//	return agi;
//};

//
void Entity::set_isDead(bool m_isDead) {
	isDead = m_isDead;
};
bool Entity::get_isDead() {
	return isDead;
};

//
void Entity::set_isAlly(bool m_isAlly) {
	isAlly = m_isAlly;
};
bool Entity::get_isAlly() {
	return isAlly;
};

//
void Entity::setRow(bool m_row) {
	row = m_row;
};
bool Entity::getRow() {
	return row;
};

// New Methods

int Entity::get_stat(stat_type in) {
	return stats[in];
};
void Entity::change_stat(stat_type stat, int change) {
	if ((stat != XHP) && (stat != XMP)) {
		stats[stat] += change;
		delta_stat[stat] += change;
		return;
	}
	//now checks for hp stuff
	if (stat == XHP) {
		int temp = stats[XHP];
		stats[XHP] -= change;
		if (stats[XHP] < 1) stat[XHP] = 1;
		delta_stat[XHP] += (stats[XHP] - temp);
		if (hp > stats[XHP]) hp = stats[XHP];
	} else {
		int temp = stats[XMP];
		stats[XMP] -= change;
		if (stats[XMP] < 1) stat[XMP] = 1;
		delta_stat[XMP] += (stats[XMP] - temp);
		if (mp > stats[XMP]) mp = stats[XMP];
	}
};
void Entity::end_battle() {
	for (size_t k = 0; k < 8; k++) stats[k] -= delta_stat[k];
	delta_stat.fill(0);
};
string Entity::get_name() {
	return name;
};
void Entity::lvl_up() {
	for (size_t k = 0; k < 8; k++) stats[k] += stat_gain[k];
	lvl++;
};
//int Entity::get_level() {
//	return level;   //There is nosetter for level on purpose
//}
//int Entity::getHp() {
//	return hp;
//}
int Entity::damage(int in) {
	int temp = hp;
	hp -= in;
	clamp(hp, 0, stats[XHP]);
	return (temp - hp);
};
void Entity::subMp(int in) {
	int temp = mp;
	mp -= in;
	clamp(hp, 0, stats[XHP]);
};
//int getMp() {
//	return mp
//}
//void Entity::set_life_status(bool in) { // True = dead, False = alive
//	isDead = in;
//};
//bool is_alive() {
//	return Still_Alive;
//}
//bool get_row() {
//	return row;
//}
//bool get_faction() {
//	return faction;
//	}
void Entity::changeRow() {
	if (row == FRONT) row == BACK;
	else row == FRONT;
};

//Start actor classes


