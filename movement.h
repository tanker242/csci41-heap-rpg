#include <iostream>
#include <cstdlib>
using namespace std;
int xCoor =0;
int yCoor =0;


void movement() {
    while (true) {
        //int xCoor = 0;
        //int yCoor = 0;
        int count = 0;
        char c;
        while (true) {
            cin >> c;
            if (c == 'a') {
                cout << "One step to the left..." << endl; 
                xCoor -= 1;
            } else if (c == 's') {
                yCoor -= 1;
                cout << "One step backwards" << endl;
            } else if (c == 'd') {
                xCoor += 1;
                cout << "one step to the right..." << endl;
            } else if (c == 'w') {
                yCoor += 1;
                cout << "one step forward!" << endl;
            }
            count++;
            if (count % 10 == 0){ 
            cout << "X coordinate =" << xCoor << endl << "Y coordinate =" << yCoor << endl;
            break;
            }
        }


        break;
    }
}
