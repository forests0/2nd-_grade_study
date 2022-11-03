#ifndef __VARIOUS_MONSTERS_H__
#define __VARIOUS_MONSTERS_H__
#define DIM 40
#include "Monster.h"
//#include "Input.h"

class Zombie: public Monster {
  public:
    Zombie(string name="좀비", char icon='!', int x=0, int y=0): Monster(name, icon, x, y) {}

    void move(int map[DIM][DIM], int xMax, int yMax) {
      srand((unsigned)time(NULL));
      switch(rand() % 8) {
        case 0: y--; break;
        case 1: x++; y--; break;
        case 2: x++; break;
        case 3: x++; y++; break;
        case 4: y++; break;
        case 5: x--; y++; break;
        case 6: x--; break;
        case 7: x--; y--; break;
      }
      clip(xMax, yMax);
      eat(map);
    }

    ~Zombie() {
      cout << "[ Zombie ] ";
    }
};

class Vampire: public Monster {
  public:
    Vampire(string name="뱀파이어", char icon='@', int x=0, int y=0): Monster(name, icon, x, y) {}

    void move(int map[DIM][DIM], int xMax, int yMax) {
      srand((unsigned)time(NULL));
      switch(rand() % 4) {
        case 0: y--; break;
        case 1: x++; break;
        case 2: y++; break;
        case 3: x--; break;
      }
      clip(xMax, yMax);
      eat(map);
    }

    ~Vampire() {
      cout << "[ Vampire ] ";
    }
};

class Jiangshi: public Monster {
  public:
    Jiangshi(string name="강시", char icon='^', int x=0, int y=0): Monster(name, icon, x, y) {}

    void move(int map[DIM][DIM], int xMax, int yMax) {
      srand((unsigned)time(NULL));
      switch(rand() % 8) {
        case 0: y--; break;
        case 1: y++; break;
        case 2: y++; break;
        case 3: y--; break;
        case 4: y++; break;
        case 5: y++; break;
        case 6: y--; break;
        case 7: y++; break;
      }
      clip(xMax, yMax);
      eat(map);
    }

    ~Jiangshi() {
      cout << "[ Jiangshi ] ";
    }
};

class Human: public Monster {
  public:
    Human(string name="강시", char icon='~', int x=0, int y=0): Monster(name, icon, x, y) {}

    void move(int map[DIM][DIM], int xMax, int yMax) {
      int xmove, ymove, fmove = 0;
        //xmove = getch();
        if(xmove != 27) return ;
        //ymove = getch();
        //fmove = getch();
        switch(fmove) {
          case 68 :
            x--;
            break;
          case 67 :
            x++;
            break;
          case 65 :
            y--;
            break;
          case 66 :
            y++;
            break;
          }
      clip(xMax, yMax);
      eat(map);
    }

    ~Human() {
      cout << "[ Human ] ";
    }
};

#endif