#include <iostream>
int main()
int** creatematrix(size_t m, size_t n);
void destroy(int** t, size_t m, size_t n);
{
  size_t M = 0, N = 0;
  std::cin >> M >> N;
  int** t  = creatematrix(M,N);
  destroy(t, M, N);
}
