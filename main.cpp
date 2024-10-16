#include <iostream>
#include "matrix.hpp"
int main()
{
  size_t M = 0, N = 0;
  std::cin >> M >> N;
  int** t  = nullptr;
  try {
    t = creatematrix(M,N);
  } catch (const std::bad_alloc & e) {
    std::cerr << "Out of memory\n";
    return 1;
  }
  input(t, M, N);
  output(t, M, N);
  destroy(t, M);
}
