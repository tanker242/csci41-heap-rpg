#include <iostream>
#include <cstdlib>
#include "Entity.h"


using namespace std;
void TestEntity();
int main()
{
//    cout << "Welcome to the RPG" << endl << "Use the ASWD keys to navigate the map" << endl; 
//    movement(); 
//	cout << "Testing functions" << endl;
//	Player stuff;
//	stuff.lvl = 5;
//	cout << stuff.getHp() << endl;
TestEntity();
//int t = 0;
//cin t;
//meow(t);
//cout << endl;
TestEntity();
};

//Function designed to test class
void TestEntity(){
	cout << "Printing all values for the following: object test of type Player." << endl;
	Entity test;
	cout << "HP:" << test.getHp() << endl;
	cout << "MP:" << test.getMp() << endl;
	cout << "Lvl:" << test.getLvl() << endl;
	cout << "Spd:" << test.getSpd() << endl;
	cout << "Xp:" << "Is currently not in use" << endl;
	cout << "Str:" << test.getStr() << endl;
	cout << "Intel:" << test.getIntel() << endl;
	cout << "Agi:" << test.getAgi() << endl;
//	cout << "isDead:" << get_isDead()  << endl; After making changes to Entity.cc and .h these break
//	cout << "isAlly:" << get_isAlly()  << endl;
//	cout << "row:" << getRow()  << endl;
};

