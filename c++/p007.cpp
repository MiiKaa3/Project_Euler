#include <iostream>
#include <vector>
#include <cstdint>
#include "./mks_pe.hpp"

int main()
{
  std::vector<uint64_t> primes { mks_pe::sieve2primes<uint64_t>(mks_pe::eratosthenesSieve(150'000)) };
  
  std::cout << primes[10'001 - 1] << std::endl;
}