#include <iostream>
using namespace std;

template <typename T>
class MyArray
{
private:
  T *arr;
  int size;
  MyArray(const MyArray &ref) {}
  MyArray &operator=(const MyArray &ref) {}

public:
  MyArray(int n){};
  int GetSize() { return size; }
  ~MyArray(){};
  T &operator[](int index){};
};

template <typename T>
MyArray<T>::MyArray(int n) : size(n) { arr = new T[n]; }

template <typename T>
MyArray<T>::~MyArray() { delete[] arr; }

template <typename T>
T &MyArray<T>::operator[](int index)
{
  if (index >= size || size < 0)
  {
    cout << "Invalid Value" << endl;
    exit(1);
  }
  return arr[index];
}
