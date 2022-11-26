#ifndef __MATRIX_H__
#define __MATRIX_H__

#include<iostream>
using namespace std;

template<typename T>
class Matrix {
private:
  int cols, rows;
  T** mat;
public:
  Matrix(int cols, int rows) : cols(cols), rows(rows), mat(NULL) {
    mat = new T*[rows];
    for(int i = 0; i < rows; i++) {
      mat[i] = new T[cols];
    }
  }

  ~Matrix() {
    for(int i = 0; i < this->rows; i++) {
      delete[] mat[i]; 
    }
    delete[] mat;
  }

  int getRows() {
    return this->rows;
  };

  int getCols() {
    return this->cols;
  };

  T& elem(int r, int c) {
    return mat[r][c];
  };

  void print() {
    cout << "Mat"<< rows << "x" << cols; 
  };

  T** getMartix() {
    return mat;    
  };
  T& operator() (int r, int c) {
    if(r >= 0 && r <= rows && c >= 0 && c <= cols ) return mat[r][c];
    else {
      cout << "Matrix" << typeid(T).name() << ">::operator(" <<r << ", " << c << ")" << endl;
      exit(-1);
    }
  }

  T*& operator[] (int r) {
    if(r >= 0 &r <= rows) return mat[r];
    else {
      cout << "Matrix" << typeid(T).name() << ">::operator[" << r << "]" << endl;
      exit(-1);
    }
  } 
  
};

#endif