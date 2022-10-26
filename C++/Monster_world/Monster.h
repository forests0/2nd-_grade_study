#include <string>
#include "Canvas.h"
#include <time.h>
using namespace std;

class Monster {
private:
    string name;
    char icon;
    int x, y, nItem;
    void clip(int xMax, int yMax) {
        if(x < 0) x= 0;
        if(x >= xMax) x = xMax - 1;
        if(y < 0) y= 0;
        if(y >= yMax) x = yMax - 1;
    }
    void eat(int map[DIM][DIM]) {
        if(map[y][x] == 1) {
            map[y][x] = 0;
            nItem++;
        }
    }
public:
    Monster(string name, char icon, int x, int y) : name(name), icon(icon), x(x), y(y), nItem(0) {};
    ~Monster() {
        cout << "\t" << name << icon <<" bye"<< endl;
    };
    void draw(Canvas& canvas) {
        canvas.draw(x,y,icon);
    };
    void move(int map[DIM][DIM], int xMax, int yMax) {
        srand(time(NULL));
        int movings = rand() % 8;
        switch(movings) {
            case 0 :
                y--; break;
            case 1 :
                x++; y--; break;
            case 2 :
                x++; break;
            case 3 :
                x++; y++; break;
            case 4 :
                y++; break;
            case 5 :
                x--; y++; break;
            case 6 :
                x--; break;
            case 7 :
                x--; y--; break;
        }
        clip(xMax, yMax);
        eat(map);
    };
    void print() {
        cout << "\t" << name << icon << " : "<< nItem << endl;
    };
};