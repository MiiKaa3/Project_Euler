#include <iostream>
#include <cstdint>

int main()
{
  constexpr uint64_t upper = 100;
  uint64_t sumOfSquares = 0;
  uint64_t squareOfSum = 0;

  for (uint64_t i = 1; i < upper + 1; ++i)
  {
    sumOfSquares += i * i;
    squareOfSum += i;
  }
  squareOfSum *= squareOfSum;
  
  std::cout << squareOfSum - sumOfSquares << std::endl;
}