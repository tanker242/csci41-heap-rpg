#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;
void fightMove (){
    string line;
    int random = 0;
    random = rand() % 470;
    int numberOfmoves = 0;
    vector<string> moves;
    ifstream File("randomMoves.txt");
    while (getline(File, line)){
        ++numberOfmoves;
        if (numberOfmoves == random) {
            cout << line<< endl;
        }
    }
}


void fight(){
    int health = 100;
    int opponent = rand() % 100;
while (true) {
        cout << "enter a number to continue" << endl << endl;
        int y = 0;
        cin >> y;
        cout << "YOU used " ;
        fightMove();
        int attack = 0;
            attack = rand() % 100;
        cout << "   and dealt  " << attack << "  damage to your opponent" << endl << endl << endl;
            opponent = opponent - attack;
        cout << "Your opponents health is  " << opponent << endl << endl;
         if (opponent <= 0){
    cout << "your opponent has died" << endl;
        break;
    }


        cout << "Your opponent used " ;
        fightMove();
            int blow = 0;
                blow = rand() %100;
        cout << "   and dealt  " << blow << "  damage" << endl << endl << endl;
            health = health - blow;
        cout << "Your health is" << health << endl << endl;
            if (health <= 0) {
    cout << "Your health = 0 and therefore you have died, please try again" << endl;
        exit(1);
    }
        }
}
