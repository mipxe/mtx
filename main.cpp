#include <iostream>
#include "matrix.hpp"

int main()
{
  size_t M = 0, N = 0;
  if (!(std::cin >> M >> N)) {
    std::cerr << "Not a number\n";
    return 1;
  }
  try
  {
    Matrix mtx(M, N);
    mtx.input(std::cin);
    if (!std::cin) {
      std::cerr << "Not a number\n";
      return 1;
    }
    mtx.output(std::cout);
    mtx.changeSize(M + 5, N + 10);
    mtx.output(std::cout);
  }
  catch(const std::bad_alloc & e)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }
}
