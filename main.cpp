#include <iostream>
#include "matrix.hpp"
int main()
{
  size_t M = 0, N = 0;
  std::cin >> M >> N;
  if (!std::cin) {
    std::cerr << "Not a number\n";
    return 1;
  int** t  = nullptr;
  try {
    t = creatematrix(M,N);
  } catch (const std::bad_alloc & e) {
    std::cerr << "Out of memory\n";
    return 1;
  }
  try {
    input(t, M, N);
  } catch (const std::invalid_argument) {
    std::cerr << "Not a number\n";
    return 1;
  }
  output(t, M, N);
  destroy(t, M);
}
