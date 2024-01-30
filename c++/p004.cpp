#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include "./mks_pe.hpp"

int main()
{
  std::vector<std::vector<int>>candidates;
  for (int i = 999; i > 99; i--)
    for (int j = i; j > 99; j--)
      if (mks_pe::isPalindrome<int>(i * j))
        candidates.emplace_back( std::initializer_list<int>{ i, j, i * j } );

  const std::vector<int>& w { *std::max_element(candidates.begin(), candidates.end(), [](const std::vector<int>& a, const std::vector<int>& b) { return a[2] < b[2]; }) };
  std::cout << w[0] << " * " << w[1] << " = " << w[2] << std::endl;
}