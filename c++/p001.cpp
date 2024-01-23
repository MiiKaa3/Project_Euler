#include <iostream>
#include <cstdint>
#include <vector>
#include <numeric>
#include <algorithm>

int main()
{
  std::vector<uint64_t> nums(999);
  std::iota(nums.begin(), nums.end(), 1);
  std::cout
    << std::accumulate(
      nums.begin(), nums.end(),
      (uint64_t)0,
      [](uint64_t a, uint64_t b) { return !(b % 3) || !(b % 5) ? a + b : a; }
    )
    << std::endl;
}