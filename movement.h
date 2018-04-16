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
                xCoor -= 1;
            } else if (c == 's') {
                yCoor -= 1;
            } else if (c == 'd') {
                xCoor += 1;
            } else if (c == 'w') {
                yCoor += 1;
            }
            cout << "X coordinate =" << xCoor << endl << "Y coordinate =" << yCoor << endl;
            count++;
            if (count % 10 == 0) break;
        }


        break;
    }
}
