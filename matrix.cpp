#include "matrix.hpp"
void input(int** t, size_t m, size_t n) {
  for (size_t i = 0; i < m; ++i) {
    for (size_t j = 0; j < n; ++j) {
      std::cin >> t[i][j];
    }
  }
}
void output(const int * const * t, size_t m, size_t n) {
  for (size_t i = 0; i < m, ++i) {
    std::cout << t[i][0];
    for (size_t j = 0; j < n; ++j) {
      std::cout << t[i][j];
    }
    std::cout << "\n";
  }
}
