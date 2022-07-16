#include <iostream>

void Sbyval(int ref1, int ref2) {
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}

void Sbyref(int *ref1, int *ref2) {
    int temp = *ref1;
    *ref1 = *ref2;
    *ref2 = temp;
}

int main(void) {
    int val1 = 10;
    int val2 = 20;

    Sbyval(val1, val2);

    Sbyref(val1, val2);
}