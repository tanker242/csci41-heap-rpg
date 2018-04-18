#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;
void fightMove (){
    string line;
    int random = 0;
    random = rand() % 467;
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




void fight (int fight){
    int health = 100;
while (health > 0){
    if (fight == 0){
    cout << "Ran from the fight" << endl;
    break;
    }
    else if ( fight != 0) {
    cout << "choose a number between 1-10" << endl;
    cout << "you used " ;
    fightMove();
    cout << "and dealt" << rand() % 100 << "damage" << endl;
    health
    cout << "Your opponent used " ;
    fightMove();
    cout << "and dealt" << (rand() % 100) << "damage" << endl;


    }
}
}
