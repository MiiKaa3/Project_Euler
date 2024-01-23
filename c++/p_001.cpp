#include <iostream>
#include <cstdint>
#include <vector>
#include <numeric>
#include <algorithm>

int main()
{
  constexpr uint64_t max = 1000;

  std::vector<uint64_t> range(max - 1);
  std::iota(range.begin(), range.end(), 1);
  
  std::vector<uint64_t> res(max - 1);
  std::transform(
    range.begin(), range.end(),
    res.begin(),
    [](int x) { return !(x % 3ULL) || !(x % 5ULL) ? x : 0; }
  );

  std::cout << std::reduce(res.begin(), res.end()) << std::endl;
}