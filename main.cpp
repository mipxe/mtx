#include <iostream>
#include "matrix.hpp"
int main()
{
  size_t M = 0, N = 0;
  std::cin >> M >> N;
  int** t  = creatematrix(M,N);
  destroy(t, M, N);
}
