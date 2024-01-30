#include <iostream>
#include <cstdint>
#include <cmath>

int main() {
  uint64_t a, b, c, cc;

  for (a = 0; a < 400; a++)
    for (b = a; b < 400; b++)
    {
      cc = a*a + b*b;
      if (c = static_cast<uint64_t>(std::sqrt(cc)); (std::sqrt(cc) == c && a + b + c == 1000))
        goto end;
    }
end:
  
  std::cout << a << " " << b << " " << c << std::endl << a * b * c << std::endl;
}