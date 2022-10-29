#include "Canvas.h"
#include "Monster.h"
#define MAX_MONSTER 20

class MonsterWorld {
private:
    int map[DIM][DIM];
    int xMax, yMax, nMon, nMove;
    Monster* mon[MAX_MONSTER];
    Canvas canvas;
public:
    MonsterWorld(int width, int height) : xMax(width), yMax(yMax) {};
    ~MonsterWorld();
    void add(Monster* m) {

    };
    void print() {

    };
    void play(int maxWalk, int wait) {
        print(); // 초기 화면 출력
        cout << " 엔터를 누르세요...";
        getchar();
        // 몬스터 움직이기
        // 변경된 화면 출력
        // wait만큼 기다리기
    }
};