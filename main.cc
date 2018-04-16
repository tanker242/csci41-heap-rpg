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
