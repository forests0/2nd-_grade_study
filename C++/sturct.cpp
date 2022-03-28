#include <iostream>

typedef struct _point {
    int xpos;
    int ypos;
}Point;

using namespace std;
Point & adder(const Point & a1, const Point & a2) {
    Point * ppr = new Point;
    ppr->xpos = a1.xpos + a2.xpos;
    ppr->ypos = a1.ypos + a2.ypos;
    return *ppr;
}
int main() {

    Point * pptr1 = new Point;
    pptr1->xpos = 3;
    pptr1->ypos = 30;

    Point * pptr2 = new Point;
    pptr2->xpos = 70;
    pptr2->ypos = 7;

    Point & pref = adder(*pptr1, *pptr2);

    cout<<pref.xpos<<pref.ypos<<endl;

    delete pptr1;
    delete pptr2;
    delete &pref;
    return 0;
}