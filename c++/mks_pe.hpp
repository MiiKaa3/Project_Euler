#ifndef MKS_PE_HPP
#define MKS_PE_HPP

namespace mks_pe
{

#include <vector>
#include <algorithm>
// #include <cstdint>

std::vector<bool> eratosthenesSieve (const size_t& n)
{
  std::vector<bool> res(n, true);
  res[0] = res[1] = false;
  for (size_t i = 2; i < n; ++i)
    if (res[i])
      for (size_t j = i*i; j<n; j+=i)
        res[j] = false;
  return res;
}

template <typename T>
std::vector<T> sieve2primes (const std::vector<bool>& sieve)
{
  std::vector<T> res;
  for (size_t i = 0; i < sieve.size(); ++i)
    if (sieve[i])
      res.push_back(static_cast<T>(i));
  return res;
}

template <typename T>
std::vector<T> sieve2composite (const std::vector<bool>&  sieve)
{
  std::vector<T> res;
  for (size_t i = 0; i < sieve.size(); ++i)
    if (!sieve[i])
      res.push_back(static_cast<T>(i));
  res.erase(res.begin());
  res.erase(res.begin());

  return res;
}

template <typename T>
std::vector<T> primeFactors (T n, const std::vector<T>& primes)
{
  std::vector<T> res;
  auto p = primes.begin();
  while (n > 1)  
  {
    while (n % *p == 0)
    {
      res.push_back(*p);
      n /= *p;
    }
    p++;
  }
  return res;
}

template <typename T>
bool isPalindrome(const T& n)
{
  std::vector<T> digits;
  for (T i = n; i > 0; i /= 10)
    digits.push_back(i % 10);
  return std::equal(digits.begin(), digits.begin() + (digits.size() / 2), digits.rbegin());
}

}

#endif