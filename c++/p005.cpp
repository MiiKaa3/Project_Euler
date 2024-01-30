#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <cstdint>
#include "./mks_pe.hpp"

int main() {
  std::vector<bool> sieve { mks_pe::eratosthenesSieve(21) };
  std::vector<int> primes { mks_pe::sieve2primes<int>(sieve) };
  std::vector<int> composites { mks_pe::sieve2composite<int>(sieve) };
  std::vector<int> multiplicands;
  
  for (const auto& c : composites)
  {
    std::vector<int> factors { mks_pe::primeFactors<int>(c, primes) };

    for (const auto& p : std::set<int>(factors.begin(), factors.end()))
    {
      int pNeeded = std::count(factors.begin(), factors.end(), p);
      int pHave = std::count(multiplicands.begin(), multiplicands.end(), p);
      for (int i = 0; i < pNeeded - pHave; ++i)
        multiplicands.push_back(p);
    }
  }

  for (const auto& p : primes)
  {
    if (!std::count(multiplicands.begin(), multiplicands.end(), p))
      multiplicands.push_back(p);
  }

  std::cout << std::accumulate(multiplicands.begin(), multiplicands.end(), 1, std::multiplies<uint32_t>()) << std::endl;
}