#include <iostream>
#include <cstdint>
#include <vector>
#include <numeric>
#include <algorithm>

int main()
{
  std::vector<uint64_t> fib { 1, 2 };
  for (size_t i = 1; fib.back() < (uint64_t)4'000'000; ++i)
    fib.push_back(fib[i] + fib[i - 1]);
  fib.pop_back();
  std::cout
    << std::accumulate(
      fib.begin(), fib.end(),
      (uint64_t)0,
      [](uint64_t a, uint64_t b) { return !(b % 2) ? a + b : a; }
    )
    << std::endl;
}