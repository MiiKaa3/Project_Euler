#include <iostream>
#include <algorithm>
#include <cstdint>
#include "./p008_vector.hpp"

int main() {
  constexpr int runSize = 13;
  std::vector<int> run(runSize);
  uint64_t runProduct = 0;

  for (size_t i = 0; i < p008Vector.size() - runSize; ++i)
  {
    uint64_t product = 1;
    for (size_t j = 0; j < runSize; ++j)
      product *= p008Vector[i + j];
    if (product > runProduct)
    {
      runProduct = product;
      for (size_t j = 0; j < runSize; ++j)
        run[j] = p008Vector[i + j];
    }
  }

  std::for_each(run.begin(), run.end(), [](const int& a){ std::cout << a << " "; });
  std::cout << std::endl << runProduct;
    return 0;
}