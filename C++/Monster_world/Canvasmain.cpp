#include "Canvas.h"

int main(void) {
    srand((unsigned int)time(NULL));
    int width = 16, height = 8;
    Canvas canvas(width, height);
    for(int i = 0 ; i < height ; i++)
        for(int j = 0 ; j < width ; j++)
            canvas.draw(j, i, '.');
    canvas.print();
    canvas.clear();
    canvas.print();
    return 0;
}