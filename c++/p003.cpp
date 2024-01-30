#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>
#include "./mks_pe.hpp"

int main()
{
  constexpr uint64_t n = 600851475143;

  std::vector<bool> sieve { mks_pe::eratosthenesSieve(10000) };
  std::vector<uint64_t> primes { mks_pe::sieve2primes<uint64_t>(sieve) };
  std::vector<uint64_t> factors { mks_pe::primeFactors<uint64_t>(n, primes) };

  std::cout << *std::max_element(factors.begin(), factors.end()) << std::endl;
}