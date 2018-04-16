#include <iostream>
#include <cstdlib>
#include "movement.h"
#include "heap.h"
#include "dialogue.h"

using namespace std;


int main() {
    cout << "Welcome to the RPG" << endl << "Use the ASWD keys to navigate the map" << endl;
    for (int i = 0; i < 10 ; i++) {
        movement();
        dialogue(i);
        // insert battle system right here, after every ten moves
    }
    cout << "game over" << endl;


}



/* Legacy testing for Entity

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
	Player test;
	cout << "HP:" << test.getHp() << endl;
	cout << "MP:" << test.getMp() << endl;
	cout << "Lvl:" << test.getLvl() << endl;
	cout << "Spd:" << test.getSpd() << endl;
	cout << "Xp:" << "Is currently not in use" << endl;
	cout << "Str:" << test.getStr() << endl;
	cout << "Intel:" << test.getIntel() << endl;
	cout << "Agi:" << test.getAgi() << endl;
	cout << "isDead:" << test.get_isDead()  << endl; 
	cout << "isAlly:" << test.get_isAlly()  << endl;
	cout << "row:" << test.getRow()  << endl;
};

*/
