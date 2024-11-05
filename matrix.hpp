#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

class Matrix
{
public:
  Matrix(size_t m, size_t n);
  Matrix(const Matrix & other);
  ~Matrix();
  size_t GetRow();
  size_t GetColumn();
  void input(std::istream & in);
  void output(std::ostream & out);
  void changeSize(size_t m, size_t n);
private:
  size_t m;
  size_t n;
  int ** t;
  void destroy(int** t, size_t m);
  int** creatematrix(size_t m, size_t n);
  void input(std::istream & in, int** t, size_t m, size_t n);
  void output(std::ostream & out, const int * const * t, size_t m, size_t n);
};

#endif
