#ifndef __HUMAN_H__
#define __HUMAN_H__

#include "Monster.h"
#include "Input.h"

class Human: public Monster {
  public:
    Human(string name="플레이어", char icon='&', int x=0, int y=0): Monster(name, icon, x, y) {}
    void move(int** map, int xMax, int yMax) {
      if(getch()) {
        int num1 = getch();
        int num2 = getch();

        if(num1 == 91) {
          if(num2 == 68) x--;
          else if(num2 == 67) x++;
          else if(num2 == 65) y++;
          else if(num2 == 66) y--;
        }
      }

      clip(xMax, yMax);
      eat(map);
    }

    ~Human() {
      cout << "[  Human] ";
    }
};

#endif