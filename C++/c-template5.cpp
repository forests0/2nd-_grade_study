#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class Point
{
private:
  T xpos, ypos;

public:
  Point(T xpos = 0, T ypos = 0) : xpos(xpos), ypos(ypos) {}
  void ShowPosition() const
  {
    cout << '[' << xpos << ", " << ypos << ']' << endl;
  }
};

template <typename T>
class SimpleDataWrapper
{
private:
  T mdata;

public:
  SimpleDataWrapper(T data) : mdata(data) {}
  void ShowDataInfo(void) const
  {
    cout << "Data: " << mdata << endl;
  }
};

template <>
class SimpleDataWrapper<char *> {
  private:
    char * mdata;
  public:
  SimpleDataWrapper(char* data) {
    this->mdata = new char[strlen(data) + 1];
    strcpy(this->mdata, data);
  }
  void ShowDataInfo(void) const
  {
    cout << "string : " << mdata << endl;
    cout << "length :  " << strlen(mdata) << endl;
  }
  ~SimpleDataWrapper() {
    delete[] mdata;
  }
};

template<typename T>
class SimpleDataWrapper<Point<T>> {
  private :
    Point<T> mdata;
  public :
    SimpleDataWrapper(T x, T y) : mdata(x, y) {}
    void ShowDataInfo() const {
      mdata.ShowPosition();
    }
};

int main(void)
{
  cout << "SimpleDataWrapper<int>" << endl;
  SimpleDataWrapper<int> iwrap(170);
  iwrap.ShowDataInfo();
  cout << endl;

  cout << "SimpleDataWrapper<char*>" << endl;
  char str[] = "ABCDE";
  SimpleDataWrapper<char *> swrap(str);
  swrap.ShowDataInfo();
  cout << endl;

  cout << "SimpleDataWrapper<Point<int>>" << endl;
  SimpleDataWrapper<Point<int>> poswrap(3, 7);
  poswrap.ShowDataInfo();

  return 0;
}