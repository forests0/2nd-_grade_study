#include <iostream>
using namespace std;

template <typename T> class MyArray {
private:
  T *arr;
  int size;
  MyArray(const MyArray &ref) {}
  MyArray &operator=(const MyArray &ref) {}

public:
  MyArray(int n) : size(n) { arr = new T[n]; }
  int GetSize() { return size; }
  ~MyArray() { delete[] arr; }
  T &operator[](int index) {
    if (index >= size || size < 0) {
      cout << "Invalid Value" << endl;
      exit(1);
    }
    return arr[index];
  }
};

class Point {
private:
  int xpos, ypos;

public:
  Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
  friend ostream &operator<<(ostream &os, const Point &p);
};

ostream &operator<<(ostream &os, const Point &p) {
  cout << "[" << p.xpos << "," << p.ypos << "]";
  return os;
}

int main() {
  /*** int형 정수 저장 ***/
  MyArray<int> iarr(5);
  for (int i = 0; i < iarr.GetSize(); i++) {
    iarr[i] = i;
  }
  for (int i = 0; i < iarr.GetSize(); i++) {
    cout << iarr[i] << endl;
  }

  /*** Point 객체 저장 ***/
  MyArray<Point> parr(3);
  parr[0] = Point(1, 2);
  parr[1] = Point(3, 4);
  parr[2] = Point(5, 6);
  for (int i = 0; i < parr.GetSize(); i++) {
    cout << parr[i] << endl;
  }

  /*** Point 객체 주소값 저장 ***/
  MyArray<Point *> pparr(3);
  pparr[0] = new Point(1, 2);
  pparr[1] = new Point(3, 4);
  pparr[2] = new Point(5, 6);
  for (int i = 0; i < pparr.GetSize(); i++) {
    cout << *(pparr[i]) << endl;
  }
}