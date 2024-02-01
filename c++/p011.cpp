#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdint>
#include "./p011_vector.hpp"
#include "./mks_pe.hpp"

int main()
{
  constexpr uint32_t len = 4;
  const uint32_t rows = p011Vector.size();
  const uint32_t cols = p011Vector.at(0).size();
  const std::vector<std::vector<uint32_t>> p011Vector_T { mks_pe::transpose(p011Vector) };
  std::vector<uint32_t> run (len, 0);
  uint32_t greatestProduct = 0;

  // Horizontal and Vertical
  // Vertical ≡ Horizontal on transpose
  // (can use same for loop because because rows = cols)
  for (size_t i = 0; i < rows; ++i)
    for (size_t j = 0; j < 1 + cols - len; ++j)
    {
      uint32_t prod = std::reduce(p011Vector.at(i).begin() + j, p011Vector.at(i).begin() + j + len, static_cast<uint32_t>(1), std::multiplies<uint32_t>());
      if (prod > greatestProduct)
      {
        greatestProduct = prod;
        std::copy(p011Vector.at(i).begin() + j, p011Vector.at(i).begin() + j + len, run.begin());
      }

      prod = std::reduce(p011Vector_T.at(i).begin() + j, p011Vector_T.at(i).begin() + j + len, static_cast<uint32_t>(1), std::multiplies<uint32_t>());
      if (prod > greatestProduct)
      {
        greatestProduct = prod;
        std::copy(p011Vector_T.at(i).begin() + j, p011Vector_T.at(i).begin() + j + len, run.begin());
      }
    }

  // Diagonal Down
  for (size_t i = 0; i < 1 + rows - len; ++i)
    for (size_t j = 0; j < 1 + cols - len; ++j)
    {
      uint32_t prod = 1;
      for (size_t k = 0; k < len; ++k)
      {
        prod *= p011Vector[i + k][j + k];
      }
      if (prod > greatestProduct)
      {
        greatestProduct = prod;
        for (size_t k = 0; k < len; ++k)
          run[k] = p011Vector[i + k][j + k];
      }
    }

  // Diagonal Up
  for (size_t i = len - 1; i < rows; ++i)
    for (size_t j = 0; j < cols; ++j)
    {
      uint32_t prod = 1;
      for (size_t k = 0; k < len; ++k)
      {
        prod *= p011Vector[i - k][j + k];
      }
      if (prod > greatestProduct)
      {
        greatestProduct = prod;
        for (size_t k = 0; k < len; ++k)
          run[k] = p011Vector[i - k][j + k];
      }
    }

  std::for_each(run.begin(), run.end(), [](const uint32_t& a) { std::cout << a << " "; });
  std::cout << std::endl << greatestProduct << std::endl;
}