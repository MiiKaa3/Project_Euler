#include <iostream>
#include <vector>
#include <cstdint>

int main()
{
  constexpr uint64_t n = 2'000'000;
  uint64_t sum = 0;
  std::vector<bool> sieve(n, true);
  sieve[0] = sieve[1] = false;
  for (size_t i = 2; i < n; ++i)
    if (sieve[i])
    {
      sum += i;
      for (size_t j = i*i; j < n; j += i)
        sieve[j] = false;
    }

  std::cout << sum << std::endl;
}