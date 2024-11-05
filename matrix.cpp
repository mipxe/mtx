#include "matrix.hpp"
#include <cstddef>
#include <iostream>
#include <cmath>

void Matrix::input(std::istream & in, int** t, size_t m, size_t n)
{
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      in >> t[i][j];
    }
  }
}

void Matrix::output(std::ostream & out, const int * const * t, size_t m, size_t n)
{
  for (size_t i = 0; i < m; ++i)
  {
    std::cout << t[i][0];
    for (size_t j = 1; j < n; ++j)
    {
      out << " " << t[i][j];
    }
    out << "\n";
  }
}

void Matrix::destroy(int** t, size_t m)
{
  for (size_t i = 0; i < m; ++i)
  {
    delete[] t[i];
  }
  delete[]t;
}

int ** Matrix::creatematrix(size_t m, size_t n)
{
  int ** t = new int*[m];
  size_t created = 0;
  try
  {
    for (;created < m; ++created)
    {
      t[created] = new int[n];
    }
  }
  catch (const std::bad_alloc & e)
  {
    destroy(t, created);
    throw;
  }
  return t;
}

Matrix::Matrix(size_t m, size_t n): m(m), n(n)
{
  t = creatematrix(m, n);
}

Matrix::Matrix(const Matrix & other): m(other.m), n(other.n)
{
  this->m = other.m;
  this->n = other.n;
  this->t = creatematrix(other.m, other.n);
  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
    this->t[i][j] = other.t[i][j];
    }
  }

}

Matrix::~Matrix()
{
  destroy(t, m);
}

size_t Matrix::GetRow()
{
  return m;
}

size_t Matrix::GetColumn()
{
  return n;
}

void Matrix::input(std::istream & in)
{
  input(std::cin, t, m, n);
}

void Matrix::output(std::ostream & out)
{
  output(std::cout, t, m, n);
}

void Matrix::changeSize(size_t newm, size_t newn)
{
  int ** newt = nullptr;
  try
  {
    newt = creatematrix(newm, newn);
  }
  catch(const std::bad_alloc & e)
  {
    throw;
  }
  for (size_t i = 0; i < newm; ++i)
  {
    for (size_t j = 0; j < newn; ++j)
    {
      newt[i][j] = 0;
    }
  }
  for (size_t i = 0; i < std::min(m, newm); ++i)
  {
    for (size_t j = 0; j < std::min(n, newn); ++j)
    {
      newt[i][j] = t[i][j];
    }
  }
  destroy(t, m);
  t = newt;
  m = newm;
  n = newn;
}