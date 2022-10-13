#include <iostream>
using namespace std;

template <typename T, int len>
class SimpleArray {
private:
    T arr[len];
public:
    T& operator[] (int idx) {
        return arr[idx];
    }
    SimpleArray<T, len>& operator=(const SimpleArray<T,len>& ref) {
        for(int i = 0; i < len; i++) {
            arr[i] = ref.arr[i];
        }
        return *this;
    }
};

int main(void) {
    SimpleArray<int, 5> int5arr1;
    for(int i = 0 ; i < 5 ; i++)
        int5arr1[i] = i;
    SimpleArray<int, 5> int5arr2;
    SimpleArray<int, 5> int5arr3;
    int5arr3 = int5arr2 = int5arr1;
    for(int i = 0 ; i < 5 ; i++)
        cout << int5arr3[i] << " ";
    cout << endl;
    
    SimpleArray<int, 7> int7arr1;
    for(int i = 0 ; i < 7 ; i++)
        int7arr1[i] = i*10;
    SimpleArray<int, 7> int7arr2;
    SimpleArray<int, 7> int7arr3;
    int7arr3 = int7arr2 = int7arr1;
    for(int i = 0 ; i < 7 ; i++)
        cout << int7arr3[i] << " ";
    cout << endl;
    return 0;
}